#pragma once
#include <iostream>
#include <vector>
#include <string> 
#include <map>
#include <unordered_map>
#include "Routes.h"
#include <algorithm>
#include <cmath>
#include <queue>

class Airport { 
  public: 
    Airport();
    Airport(int id1, std::string name1, std::string city1, std::string country1, std::pair<double, double> coordinates1,std::string iata1);
    int get_AirportId();
    std::string get_AirportCity();
    std::string get_AirportCountry();
    std::string get_AirportName();
    std::string get_AirportIATA();
    std::pair<double, double> get_AirportCoordinates();
    friend std::ostream& operator<<(std::ostream& os, Airport a);
    friend bool operator<(Airport, Airport);

  private: 
    int id;
    std::string name;
    std::string city;
    std::string country;
    std::pair<double, double> coordinates; //latitude / longitude
    std::string iata;
};

class GraphPort {
  public:
    GraphPort();
    GraphPort(const std::string&, const std::string&);
    void getairports(const std::string & filename);
    std::vector<Airport> get_airports();
    void createGraph();
    unordered_map<int, vector<int>> getGraph();
    void makeEdges();
    void build_edge();
    double calculateDistance(double start_x, double start_y, double end_x, double end_y);
    double find_distance(std::string code1, std::string code2);
    std::map<Airport, std::vector<std::pair<Airport, double>>> get_adjList();
    Airport IataToAirport(std::string iata);
    vector<std::string> departureVector;
    vector<std::string> destinationVector;
    std::vector<Airport> BFS(Airport air);
    
  private: 
    std::vector<Airport> airports;
    std::map<Airport, std::vector<std::pair<Airport, double>>> adj_list;
};

