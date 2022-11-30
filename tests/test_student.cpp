#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <string>

#include "Objects/Airport.h"
#include "Objects/Routes.h"

using std::cout;
using std::endl;
using std::string;


TEST_CASE("PUT YOUR TESTS HERE!!!", "[tag1][tag2]") {
    // Feel free to use this to put your own test cases.
    // Look at other test files for inspiration!
    string expected = "Grape";
    string actual = "Grape";
    REQUIRE(expected == actual);
}

TEST_CASE("Test Airports Parsing", "[airport]") {
  std::pair<double, double> t;
  t.first = 0.0;
  t.second = 0.0;
  
  Airport a(0, "test", "test","test", t,"test");

  a.getairports("../data/airportsub.dat");
  
  std::vector<Airport> vect = a.get_airports();

  std::cout << vect[0] << std::endl;

  
  REQUIRE(vect[0].get_AirportCity() == "\"Goroka\"");
  REQUIRE(vect[0].get_AirportCountry() == "\"Papua New Guinea\"");
  REQUIRE(vect[0].get_AirportName() == "\"Goroka Airport\"");

}