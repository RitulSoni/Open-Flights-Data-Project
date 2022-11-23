#include "Airport.h"
#include <string>

  Airport::Airport() {
    coord.first = 0;
    coord.second = 0;
  }
  int Airport::get_AirportId() {
    return id;
  }
  std::string Airport::get_AirportCity() {
    return city;
  }
  std::string Airport::get_AirportCountry() {
    return country;
  }
  std::string Airport::get_AirportName() {
    return name;
  }
  std::pair<double, double> Airport::get_AirportCoordinates() {
    return coord;
  }

