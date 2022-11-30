#include "Airport.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

Airport::Airport() {
  coordinates.first = 0;
  coordinates.second = 0;
}

Airport::Airport(int id1, std::string name1, std::string city1, std::string country1, std::pair<double, double> coordinates1,std::string iata1) {
  id = id1;
  name = name1;
  city = city1;
  country = country1;
  coordinates = coordinates1;
  iata = iata1;
}


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

void Airport::getairports(const std::string & filename) {
  ifstream f(filename);
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
      lat = stod(temp);
      temp = "";
      getline(inputString, temp, ',');
      lon = stod(temp);

      coordinates = pair<double, double>(lat, lon);
      Airport air(id, name, city, country, coordinates, iata);
      //std::cout << "object made" << std::endl;
      airports.push_back(air);
      //std::cout << "obkect push back" << std::endl;
    }
  } else {
    std::cout << "file does not work" << std::endl;
  }
}

std::vector<Airport> Airport::get_airports() {
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
