#pragma once
#include <iostream>
#include <vector>
#include <string> 
#include <map>

class Airport {
  public:
    Airport();
    Airport(int id, std::string name, std::string city, std::string country, std::pair<double, double> coordinates,std::string iata);
    int get_AirportId();
    std::string get_AirportCity();
    std::string get_AirportCountry();
    std::string get_AirportName();
    std::pair<double, double> get_AirportCoordinates();
    void getairports(const std::string & filename);
    std::vector<Airport> get_airports();
  private: 
    int id;
    std::string name;
    std::string city;
    std::string country;
    std::pair<double, double> coordinates; //latitude / longitude
    std::string iata;
    std::vector<Airport> airports;
};