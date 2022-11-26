#include "Routes.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

void Route::getroutes(const std::string & filename) {
  std::ifstream file(filename);
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