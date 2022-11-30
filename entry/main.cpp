#include "Objects/Airport.h"
#include "Objects/Routes.h"
#include <vector>
#include <iostream>

int main() {
  std::cout << "hello world" << std::endl;
  std::pair<double, double> t;
  t.first = 0.0;
  t.second = 0.0;
  
  Airport a(0, "test", "test","test", t,"test");

  a.getairports("../data/airportsub.dat");
  
  std::vector<Airport> vect = a.get_airports();

  std::cout << vect[0] << std::endl;
 //tests for airport class
  Route r;
  r.getroutes("../data/routesub.dat"); //data getter / parsing
  std::vector<Route> rout = r.get_routes();
  std::cout << rout[1] << std::endl;
  
  return 0;
}