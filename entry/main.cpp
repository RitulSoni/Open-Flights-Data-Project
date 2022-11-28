#include "/workspaces/CS225/release-f22/CS225-Final-Project/src/Objects/Airport.h"
#include <vector>
#include <iostream>

int main() {
  std::cout << "hello world" << std::endl;
  std::pair<double, double> t;
  t.first = 0.0;
  t.second = 0.0;
  Airport a(0, "test", "test","test", t,"test");
  a.getairports("airports.dat");
  
  std::vector<Airport> vect = a.get_airports();

  //std::cout << vect[2].get_AirportCity() << std::endl;

  
  return 0;
}