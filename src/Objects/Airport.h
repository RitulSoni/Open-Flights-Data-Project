
#include <iostream>
#include <vector>


class Airport {
  public:
    Airport();

    int get_AirportId();
    std::string get_AirportCity();
    std::string get_AirportCountry();
    std::string get_AirportName();
    std::pair<double, double> get_AirportCoordinates();

  private: 
    int id = 0;
    std::string name = "";
    std::string city = "";
    std::string country = "";
    std::pair<double, double> coord;
};