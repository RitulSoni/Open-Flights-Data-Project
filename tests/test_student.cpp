#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>

#include "Objects/Airport.h"
#include "Objects/Routes.h"


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
  REQUIRE(adjacents == 66475);  // These are the routes which had codes that existed in our airports dataset 
  REQUIRE(airports.size() == 7698); 
  REQUIRE(a.departureVector.size() == a.destinationVector.size());
}

TEST_CASE("BFS", "[bfs]") {
  REQUIRE(a.num_connectedComponents() > 1);
  Airport chicago = a.IataToAirport("ORD");
  Airport losangeles = a.IataToAirport("LAX");
  REQUIRE(a.BFS(chicago, true).size() > 3000);
  REQUIRE(a.BFS(chicago, true).size() == a.BFS(losangeles, true).size());
}

TEST_CASE("PageRank", "[pr]") {
  a.printAirportRanking(5, true);
  std::vector<std::pair<double, Airport>> testmap = a.getAirportRanking();
  
  REQUIRE(testmap[0].second.get_AirportIATA() == "ATL");
  REQUIRE(testmap[1].second.get_AirportIATA() == "DME");
  REQUIRE(testmap[2].second.get_AirportIATA() == "DFW");
  REQUIRE(testmap[3].second.get_AirportIATA() == "DEN");
  REQUIRE(testmap[4].second.get_AirportIATA() == "ORD");
}

TEST_CASE("Dijkstras", "[dijk]") {
  // There is a direct path from these two airports
  Airport test1 = a.IataToAirport("ORD");
  Airport dest1 = a.IataToAirport("JFK");
  // There does not exist a direct path from these two airports, so path must be greater than 2
  // In this case, there exists a intermediate path which connects both airports, so size must be three 
  Airport test2 = a.IataToAirport("PLU");
  Airport dest2 = a.IataToAirport("ORD");
  // These two are not in the same connected component, so it is impossible to reach each other
  Airport test3 = a.IataToAirport("KNQ");
  Airport dest3 = a.IataToAirport("LAX");

  std::map<Airport, std::vector<std::pair<Airport, double>>> adj_list = a.get_adjList();
  
  std::vector<Airport> output1 = a.dijkstras(test1, dest1); 
  std::vector<Airport> output2 = a.dijkstras(test2, dest2);

  REQUIRE(output1.size() == 2);
  REQUIRE(output2.size() == 3);
  REQUIRE_THROWS(a.dijkstras(test3, dest3));


}
