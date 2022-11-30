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
        std::string get_RouteAirline();
        std::string get_RouteSource();
        std::string get_RouteDest();
        vector<int> getDestVect();
        vector<int> getSourceVect();
        int get_RouteAirlineID();
        int get_RouteNumStop();
        std::vector<Route> get_routes();
        friend std::ostream& operator<<(std::ostream& os, Route r);
    private:
        string airline;
        int airline_id;
        string source_airport;
        string destination_airport;
        int num_stops;
        std::vector<Route> routes;
};