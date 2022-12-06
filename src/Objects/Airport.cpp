#include "Airport.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;
GraphPort::GraphPort(const std::string& airportFile, const std::string& routeFile) {
  Route r;
  getairports(airportFile);
  r.getroutes(routeFile);
  departureVector = r.getSourceVect();
  destinationVector = r.getDestVect();
}

Airport::Airport(int id1, std::string name1, std::string city1, std::string country1, std::pair<double, double> coordinates1,std::string iata1) {
  id = id1;
  name = name1;
  city = city1;
  country = country1;
  coordinates = coordinates1;
  iata = iata1;
  
}
Airport::Airport() { }
int Airport::get_AirportId() {
  return id;
}
std::string Airport::get_AirportCity() {
  return city;
}
std::string Airport::get_AirportCountry() {
  return country;
}
std::string Airport::get_AirportName() {
  return name;
}
std::string Airport::get_AirportIATA() {
  return iata;
}
std::pair<double, double> Airport::get_AirportCoordinates() {
  return coordinates;
}

void GraphPort::getairports(const std::string & filename) {
  ifstream f(filename);
  int count = 0;
  int count2 = 0;
  //f.open(filename);
  if (f.is_open()) {
    string line = "";
    while (getline(f, line)) {
      //std::cout << "line" << std::endl;
      std::string name, city, country, iata;
      double lat, lon;
      int id;
      string temp = "";
      stringstream inputString(line);
      
      string a, b;

      getline(inputString, temp, ','); //jsut to convert string to int
      id = stoi(temp);
      temp = "";
      getline(inputString, name, ',');
      getline(inputString, city, ',');
      getline(inputString, country, ',');
      getline(inputString, iata, ',');
      getline(inputString, temp, ','); //this will get the ICAO field, something we do not need so we will skip it
      temp = "";
      getline(inputString, temp, ',');
      a = temp;
      // this is bascially just ignoring all of the issues - not a long term solution
      try {
        lat = stod(temp);
        temp = "";
        getline(inputString, temp, ',');
        lon = stod(temp);
        auto coordinates = pair<double, double>(lat, lon);
        name.pop_back();
        name.erase(0,1);
        iata.pop_back();
        iata.erase(0,1);
        count++;

        Airport air(id, name, city, country, coordinates, iata);
        
        //std::cout << "object made" << std::endl;
        airports.push_back(air);
        //std::cout << "obkect push back" << std::endl;
      } catch (...) {
        count2++;
      }
    }
  } else {
    std::cout << "file does not work" << std::endl;
  }
  std::cout << count << " and " << count2 << std::endl;
}

std::vector<Airport> GraphPort::get_airports() {
  return airports;
}

std::ostream& operator<<(std::ostream& os, Airport a) {
  os << "Airport ID: " << a.get_AirportId() << std::endl;
  os << "Airport Name: " << a.get_AirportName() << std::endl;
  os << "Airport City: " << a.get_AirportCity() << std::endl;
  os << "Airport Country: " << a.get_AirportCountry() << std::endl;
  std::pair<double, double> coords = a.get_AirportCoordinates();
  os << "Airport Latitude: " << coords.first << std::endl;
  os << "Airport Longitude: " << coords.second << std::endl;
  os << "Airport IATA Code: " << a.get_AirportIATA() << std::endl;
  return os;
}

//_________________Graph Work_____________________________

void GraphPort::build_edge() {
    //traverse through starting airports and push back each route int
    for (size_t i = 0; i < departureVector.size(); i++) {
        Airport curr_dep = IataToAirport(departureVector[i]);
        if (adj_list.find(curr_dep) != adj_list.end()) {
          continue;
        } else {
          vector<pair<Airport,double>> second;
          adj_list.insert({curr_dep, second});
        }
    }
    for (size_t i = 0; i < destinationVector.size(); i++) {
      Airport curr_dest = IataToAirport(destinationVector[i]);
      Airport curr_dep = IataToAirport(departureVector[i]);
      double distance = calculateDistance(curr_dest.get_AirportCoordinates().first, curr_dest.get_AirportCoordinates().second, curr_dep.get_AirportCoordinates().first, curr_dep.get_AirportCoordinates().first);
      pair<Airport,int> ins (curr_dest, distance);
      adj_list[curr_dep].push_back(ins);
    }
}

double GraphPort::calculateDistance(double start_x, double start_y, double end_x, double end_y) {
    return sqrt(((start_x - start_y) * (start_x - start_y)) + ((end_x - end_y) * (end_x - end_y)));
}

std::map<Airport, std::vector<std::pair<Airport, double>>> GraphPort::get_adjList() {
  return adj_list;
}

Airport GraphPort::IataToAirport(std::string iata) {
  for (size_t i = 0; i < airports.size(); i++) {
    if (airports[i].get_AirportIATA() == iata) {
      return airports[i];
    }
  }
  return Airport();
}

// Given two Airport codes, iterates through airports to find the corresponding location, and then calculates the distance between them
double GraphPort::find_distance(std::string code1, std::string code2) {
// There are two airport codes given
// We need to figure out the coordinates of both of those airports 
  double start_x;
  double start_y;
  double end_x;
  double end_y;
  for (size_t i = 0; i < airports.size(); i++) {
    if (airports[i].get_AirportIATA() == code1) {
      start_x = airports[i].get_AirportCoordinates().first;
      start_y = airports[i].get_AirportCoordinates().second;
    }
    if (airports[i].get_AirportIATA() == code2) {
      end_x = airports[i].get_AirportCoordinates().first;
      end_y = airports[i].get_AirportCoordinates().second;
    }
  }
  return calculateDistance(start_x, start_y, end_x, end_y);
}

bool operator<(Airport a1, Airport a2) {
  return a1.get_AirportId() < a2.get_AirportId();
}


// ____________ Algorithms 
std::vector<Airport> GraphPort::BFS(Airport air) {
  vector<Airport> output;
  map<Airport, bool> visited;
  queue<Airport> queue;
  queue.push(air);
  Airport curr = air;
  GraphPort a("../data/airports.dat", "../data/routes.dat");
  a.build_edge();
  std::map<Airport, std::vector<std::pair<Airport, double>>> adj_list = a.get_adjList();
 
  while (!queue.empty()) {
    curr = queue.front();
    if (visited[curr]) {
      queue.pop();
      continue;
    }
    for (std::pair<Airport, double> air : adj_list[curr]) {
      queue.push(air.first);
    }
    visited[curr] = true;
    output.push_back(curr);
    queue.pop();
    visited.insert({air, true});
  }
  return output;
}