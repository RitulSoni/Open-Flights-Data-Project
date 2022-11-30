#include "Routes.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

Route::Route() {}

Route::Route(string airline1, int airline_id1, string source_airport1, string destination_airport1, int num_stops1) {
  airline = airline1;
  airline_id = airline_id1;
  source_airport = source_airport1;
  destination_airport = destination_airport1;
  num_stops = num_stops1;
}


void Route::getroutes(const std::string & filename) {
  ifstream file(filename);
  if (file.is_open()) {
    string line = "";
    while (getline(file, line)) {
      std::string airline, source_airport, destination_airport;
      int airline_id, num_stops;
      string temp = "";
      stringstream inputString(line);

      getline(inputString, airline, ','); 
      
      getline(inputString, temp, ',');
      airline_id = stoi(temp);
      temp = "";

      getline(inputString, source_airport, ',');
      getline(inputString, temp, ','); //gets source airport id, we dont need (possibly)
      temp = "";

      getline(inputString, destination_airport, ',');
      getline(inputString, temp, ','); //destination airport id, we dont need(possibly)
      temp = "";

      getline(inputString, temp, ','); //code share value, we dont need (possibly)
      temp = "";

      getline(inputString, temp, ',');
      num_stops = stoi(temp);

      Route rout(airline, airline_id, source_airport, destination_airport, num_stops);
      routes.push_back(rout);
    }
  }
}
std::string Route::get_RouteAirline() {
  return airline;
}
std::string Route::get_RouteSource() {
  return source_airport;
}
std::string Route::get_RouteDest() {
  return destination_airport;
}

vector<int> Route::getDestVect() {
    vector<int> destinations;
    for (size_t i = 0; i < routes.size(); ++i) {
      destinations.push_back(stoi(routes[i].get_RouteDest()));
    }
    return destinations;
}

vector<int> Route::getSourceVect() {
    vector<int> source;
    for (size_t i = 0; i < routes.size(); ++i) {
      source.push_back(stoi(routes[i].get_RouteSource()));
    }
    return source;
}


int Route::get_RouteAirlineID() {
  return airline_id;
}
int Route::get_RouteNumStop() {
  return num_stops;
}

std::vector<Route> Route::get_routes() {
  return routes;
}

std::ostream& operator<<(std::ostream& os, Route r) {
  os << "Route Airline: " << r.get_RouteAirline() << std::endl;
  os << "Airline ID: " << r.get_RouteAirlineID() << std::endl;
  os << "Source Airport: " << r.get_RouteSource() << std::endl;
  os << "Destination Airport: " << r.get_RouteDest() << std::endl;
  os << "Number of Stops: " << r.get_RouteNumStop() << std::endl;
  return os;
}