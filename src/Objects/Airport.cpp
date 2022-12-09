#include "Airport.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

// ________________ Graphport Constructors ___________________
GraphPort::GraphPort(const std::string& airportFile, const std::string& routeFile) {
  Route r;
  getairports(airportFile);
  r.getroutes(routeFile);
  departureVector = r.getSourceVect();
  destinationVector = r.getDestVect();
  this->build_edge();
}
// ________________ Airport Constructors ___________________
Airport::Airport(int id1, std::string name1, std::string city1, std::string country1, std::pair<double, double> coordinates1,std::string iata1) {
  id = id1;
  name = name1;
  city = city1;
  country = country1;
  coordinates = coordinates1;
  iata = iata1;
  
}
Airport::Airport() { }
Airport::Airport(int id2) {
  id = id2;
}

// ________________ Parsing ___________________
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
        
        airports.push_back(air);
    }
  } else {
    std::cout << "file does not work" << std::endl;
  }
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

bool operator<(Airport a1, Airport a2) {
  return a1.get_AirportId() < a2.get_AirportId();
}

//_________________ Graph Construction _____________________________
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
      if (curr_dep.get_AirportId() == -1 || curr_dest.get_AirportId() == -1) {
        continue;
      }
      double distance = calculateDistance(curr_dest.get_AirportCoordinates().first, curr_dest.get_AirportCoordinates().second, curr_dep.get_AirportCoordinates().first, curr_dep.get_AirportCoordinates().first);
      pair<Airport,double> ins (curr_dest, distance);
      adj_list[curr_dep].push_back(ins);
    }
}

double GraphPort::calculateDistance(double start_x, double start_y, double end_x, double end_y) {
    return sqrt(((start_x - start_y) * (start_x - start_y)) + ((end_x - end_y) * (end_x - end_y)));
}

// ____________ Helper Functions ____________
Airport GraphPort::IataToAirport(std::string iata) {
  for (size_t i = 0; i < airports.size(); i++) {
    if (airports[i].get_AirportIATA() == iata) {
      return airports[i];
    }
  }
  count12++;
  return Airport(-1);
}

double GraphPort::find_distance(std::string code1, std::string code2) {
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

// ____________ BFS Traversals ____________
std::vector<Airport> GraphPort::BFS(Airport air, bool flag) {
  if (flag) visited = map<Airport, bool>();
  vector<Airport> output;
  queue<Airport> queue;
  queue.push(air);
  Airport curr = air;
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

int GraphPort::num_connectedComponents() {
  std::vector<std::vector<Airport>> components;
  int output = 0;
  for (size_t i = 0; i < airports.size(); i++) { 
    if (visited[airports[i]]) continue;
    std::vector<Airport> push = BFS(airports[i], false);
    components.push_back(push);
  }
  for (size_t i = 0; i < components.size(); i++) { 
    componentSizes.push_back(components[i].size() * 2);
    if (components[i].size() > 2) output++;
  }
  return output;
}
// ________________ PageRank Algorithm ___________________
void GraphPort::pageRank() {
  // intialize each Airports with the same rank
  for (size_t i = 0; i < airports.size(); i++) {
    rankingMap.insert({airports[i], 1.0 / airports.size()});
  }

  //Take the old page rank for every web page and equally share it with every adjacent 
  for (size_t i = 0; i < rankingMap.size(); i++) {
    std::vector<std::pair<Airport, double>> adjacencies_atI = adj_list[airports[i]];
    for (size_t j = 0; j < adjacencies_atI.size(); j++) {
      Airport airport = adjacencies_atI[j].first;
      double sum = rankingMap[airport];
      double d = 0.8;
      rankingMap[airport] += (d * (sum / adjacencies_atI.size()));
    }
  }

}

// ____________________Dijkstras_______________________
std::vector<Airport> GraphPort::dijkstras(Airport a, Airport b) {
  if (BFS(a, true).size() != BFS(b, true).size()) throw invalid_argument("Airports are not in the same connected component:");
  std::vector<Airport> output;
  output.push_back(a);
  const double INF = 1e9;
  bool print = false;
  //GraphPort g;
  map<Airport, double> distance;
  std::vector<std::pair<Airport, double>> adjlistAtA = adj_list[a]; //gets the adjancey list for airport A (source)
  if (check_adjacencies(adj_list[a], b)) {
    std::cout << "There already Exists a direct route between these two airports" << std::endl;
    output.push_back(b);
    return output;
  }
  priority_queue<pair<Airport, double>, vector<pair<Airport, double>>, greater<pair<Airport, double>>> pq; //priority queue of unvisited nodes
  int size = adjlistAtA.size();
  //distance.resize(size, INF);
  for (auto& [port, neighbors] : adjlistAtA) {
    distance[port] = INF;
  }
  //vector<Airports> toreturn;
  distance[a] = 0;
  bool flag = false;
  pq.push({a, 0});
  int testCount = 0;
  while (!pq.empty()) {
    testCount++;
    Airport curr = pq.top().first;
    double curr_dist = pq.top().second;
    pq.pop();
    std::vector<std::pair<Airport, double>> adjacents = adj_list[curr];
    if (check_adjacencies(adjacents, b)) break; // If there exists a direct link from current airport to destination, break
    if (curr.get_AirportIATA() == b.get_AirportIATA()) break;
    // This intializes a map of Airport and bools to check if any of the adacencies in its list have a direct link to Airport b 
    std::map<Airport, bool> if_canVisit;
    for (size_t i = 0; i < adjacents.size(); i++) {
      Airport first = adjacents[i].first;
      bool second = check_adjacencies(adj_list[adjacents[i].first], b);
      // std::cout << adjacents[i].first.get_AirportIATA() << " : " << second << + " "; 
      if_canVisit.insert({first, second});
    }

    double min = 9999999;
    bool found = false;
    std::pair<Airport, double> to_insert;
    // This is checking the map of Airport and bools to see if theres any trues 
    for (size_t i = 0; i < adjacents.size(); i++) {
      if (if_canVisit[adjacents[i].first] == true) {
        if (adjacents[i].second < min) {
          found = true; // flag to determine a true has been found
          to_insert.first = adjacents[i].first;
          to_insert.second = adjacents[i].second;
          min = adjacents[i].second;
        }
      }
    }
    if (found) {
      output.push_back(to_insert.first);
      pq.push(to_insert);
    }

    else {
      for (const auto& [air, dist] : adjlistAtA) { //for all Airport Distance in a's adjancey list
        if (distance[curr] + dist < distance[air]) {
          distance[air] = distance[curr] + dist;
          pq.push({air, distance[air]});
        }
      }
    }
  }
  output.push_back(b);
  return output;
}

bool GraphPort::check_adjacencies(std::vector<std::pair<Airport, double>> adjlist, Airport b) {
  for (size_t i = 0; i < adjlist.size(); i++) {
      if (adjlist[i].first.get_AirportIATA() == b.get_AirportIATA()) return true;
    }
  return false;
}

// ________________ Airport Getter Functions ___________________
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
// ________________ Graphport Getters ___________________
std::vector<Airport> GraphPort::get_airports() {
  return airports;
}

std::map<Airport, std::vector<std::pair<Airport, double>>> GraphPort::get_adjList() {
  return adj_list;
}

std::map<Airport, double> GraphPort::getPageRankMap() {
  pageRank();
  return rankingMap;
}
std::vector<std::pair<double,Airport>> GraphPort::getAirportRanking() {
  return AirportRanking;
}
// ________________ PrintStatements___________________
void GraphPort::printComponentSizes(int n) { 

  sort(componentSizes.begin(), componentSizes.end());
  int j = 0;
  cout << "\t Size of largest three components: ";
  for (int i = componentSizes.size() - 1; j < n; i--) {
    cout << componentSizes[i];
    if (j != (n-1)) cout << ", ";
    j++;
  }
}

void GraphPort::printAirportRanking(int n, bool flag) {
  std::vector<std::pair<double,Airport>> values;
  pageRank();
  for (size_t i = 0; i < rankingMap.size(); i++) {
    values.push_back({rankingMap[airports[i]], airports[i]});
  }
  sort(values.begin(), values.end());
  for (int i = 0; i < n; i++) {
    AirportRanking.push_back(values.back());
    if (flag) std::cout << "\t Rank: " << i << " Airport: " << values.back().second.get_AirportIATA() << endl;
    values.pop_back();
  }
}
