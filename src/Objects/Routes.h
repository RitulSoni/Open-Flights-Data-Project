#pragma once
#include <iostream>
#include <vector>
#include <string> 
#include <map>

using namespace std;

class Route {
    public:
        Route();
        Route(string airline, int airline_id, string source_airport, string destination_airport, int num_stops);
        void getroutes(const std::string & filename);
    private:
        string airline;
        int airline_id;
        string source_airport;
        string destination_airport;
        int num_stops;
        std::vector<Route> routes;
};