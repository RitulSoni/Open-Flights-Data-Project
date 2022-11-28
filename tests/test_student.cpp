#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>

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