#include "Objects/Airport.h"
#include "Objects/Routes.h"
#include <vector>
#include <iostream>

int main() {
  GraphPort a("../data/airports.dat", "../data/routes.dat");
  std::vector<Airport> airports = a.get_airports();
  std::map<Airport, std::vector<std::pair<Airport, double>>> adj_list = a.get_adjList(); 
  int count = 0;
  for (size_t i = 0; i < 5000; i++) {
    if (adj_list[airports[i]].size() < 5) {
      count++;
    }
  }
  std::cout << "num of sizes below 5: " << count << std::endl;
  return 0;
}



  // for (size_t i = 0; i < airports.size(); i+= 100) {
  //   std::cout << airports[i].get_AirportId() << std::endl;
  // }

  // for (size_t i = 0; i < 15; i++) {
  //   Airport test = airports[i]; 
  //   std::cout << "Airport Name: " << test.get_AirportName() << " Airport Iata: " << test.get_AirportIATA() << std::endl;
  //   for (size_t i = 0; i < adj_list[test].size(); i++) {
  //     std::vector<std::pair<Airport, double>> adj = adj_list[test];
  //     std::cout << " \t Adjacency " << i << ": " << adj[i].first.get_AirportIATA() << " Distance: " << adj[i].second << std::endl;
  //   }
  // }
