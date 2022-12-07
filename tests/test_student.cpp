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

  static GraphPort a("../data/airports.dat", "../data/routes.dat");
  std::vector<Airport> airports = a.get_airports();

TEST_CASE("Test Airports Parsing", "[airport]") {
  Airport test = airports[0];
  REQUIRE(test.get_AirportId() == 1);
  REQUIRE(test.get_AirportCoordinates().first == -6.081689834590001);
}


TEST_CASE("Test find distance", "[distance]") {
  REQUIRE (a.find_distance("ORD", "JFK") < a.find_distance("ORD", "LAX"));
}
// Test for Adjacency List, Routes.dat, Airports.dat
TEST_CASE("Missing Data Check", "[routes]") {
  std::map<Airport, std::vector<std::pair<Airport, double>>> adj_list = a.get_adjList();
  int adjacents = 0;
  for (size_t i = 0; i < airports.size(); i++) {
    adjacents += adj_list[airports[i]].size();
  }
  std::cout << "Routes: " << adjacents << "  Airports: " << airports.size() << std::endl;
  REQUIRE(adjacents > 66184); 
  REQUIRE(airports.size() == 7698); 
  REQUIRE(a.departureVector.size() == a.destinationVector.size());
}

// TEST_CASE("BFS", "[bfs]") {
//   std::vector<Airport> test = a.BFS(airports[1]);
  
// }

TEST_CASE("PageRank", "[pr]") {
  std::vector<std::pair<double, Airport>> testmap = a.AirportRanking(5);
  // for (size_t i = 0; i < testmap.size(); i++) {
  //   std::cout << "Rank: " << i + 1 << " Airport: " << testmap[i].second.get_AirportIATA() << std::endl;
  // }
  REQUIRE(testmap[0].second.get_AirportIATA() == "ATL");
  REQUIRE(testmap[1].second.get_AirportIATA() == "DME");
  REQUIRE(testmap[2].second.get_AirportIATA() == "DFW");
  REQUIRE(testmap[3].second.get_AirportIATA() == "DEN");
  REQUIRE(testmap[4].second.get_AirportIATA() == "ORD");
}
