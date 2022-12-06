#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>

#include "Objects/Airport.h"
#include "Objects/Routes.h"
#include "Objects/Algorithms.h"


using std::cout;
using std::endl;
using std::string;

using namespace std;

GraphPort a("../data/airports.dat", "../data/routes.dat");
std::vector<Airport> airports = a.get_airports();


// TEST_CASE("Test Airports Parsing", "[airport]") {
//   Airport test = airports[0];
//   REQUIRE(test.get_AirportId() == 1);
//   REQUIRE(test.get_AirportCoordinates().first == -6.081689834590001);
// }

// // test if destination vector is equal to departure vector
// TEST_CASE("Test Adjancency List", "[GRAPH]") {
//   a.build_edge();
//   std::map<Airport, std::vector<std::pair<Airport, double>>> adj_list = a.get_adjList();
//   Airport first_airport = airports[0];
//   std::vector<std::pair<Airport, double>> adjacents = adj_list[first_airport];
  
// }

// TEST_CASE("Test find distance", "[distance]") {
//   REQUIRE (a.find_distance("ORD", "JFK") < a.find_distance("ORD", "LAX"));
// }

TEST_CASE("Missing Data Check", "[routes]") {
  a.build_edge();
  std::map<Airport, std::vector<std::pair<Airport, double>>> adj_list = a.get_adjList();
  int count = 0;
  for (size_t i = 0; i < airports.size(); i++) {
    count += adj_list[airports[i]].size();
  }
  std::cout << "Routes: " << count << "  Airports: " << airports.size() << std::endl;
  REQUIRE(count > 1298); // this is just for the routesSub.dat
  REQUIRE(airports.size() > 14109); // this will work once we stop omitting 
}

// TEST_CASE("Test BFS iteration" "[BFS]") {
//   a.build_edge();
//   std::map<Airport, std::vector<std::pair<Airport, double>>> adj_list = a.get_adjList();
//   REQUIRE(a.BFS(airports[0]).size() == airports.size()); // This will pass once routes.dat works 
// }
