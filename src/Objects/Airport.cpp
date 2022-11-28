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
std::pair<double, double> Airport::get_AirportCoordinates() {
  return coordinates;
}

void Airport::getairports(const std::string & filename) {
  std::ifstream file(filename);
  if (file.is_open()) {
    string line = "";
    while (getline(file, line)) {
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
      airports.push_back(air);
    }
  }
}

std::vector<Airport> Airport::get_airports() {
  return airports;
}

void Airport::hello() {
  std::cout << "hello world2" << std::endl;
}