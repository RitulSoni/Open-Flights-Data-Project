#include "Objects/Airport.h"
#include "Objects/Routes.h"
#include <vector>
#include <iostream>

int main() {
  // std::cout << "hello world" << std::endl;

  GraphPort a("../data/airports.dat", "../data/routes.dat");
  std::vector<Airport> airports = a.get_airports();
  a.build_edge();
  std::map<Airport, std::vector<std::pair<Airport, double>>> adj_list = a.get_adjList(); 
  return 0;
}

