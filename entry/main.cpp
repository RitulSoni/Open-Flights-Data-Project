#include "Objects/Airport.h"
#include "Objects/Routes.h"
#include <vector>
#include <iostream>


int main() {
  GraphPort a("../data/airports.dat", "../data/routes.dat");
  std::vector<Airport> airports = a.get_airports();
  std::map<Airport, std::vector<std::pair<Airport, double>>> adj_list = a.get_adjList();

  cout << "\n";
  cout << "\n _______________________________ CS225 Final Project: OpenFlights _______________________________" << endl;
  cout << "\n";
  cout << "Team: Kazmain Shah, Keshav Trika, Ritul Soni" << endl;
  cout << "\n";
  cout << "The OpenFlights dataset is an opensource file which contains information concerning Airports and Routes" << endl;
  cout << "\n _______________________________ Data Files _______________________________" << endl;
  cout << "\n";
  cout << "Our airports are all stored in airports.dat, with each line being an Airport object" << endl;
  cout << "\t Properties of the Airport object include:" << endl;
  cout << "\t -Airport id," << endl;
  cout << "\t -Airport name," << endl;
  cout << "\t -Airport Iata," << endl;
  cout << "\t -City and Country," << endl;
  cout << "\t -Coordinates of station " << endl;
  cout << "\n" << endl;
  cout << "Our airplane routes are all stored in routes.dat, with each line being an Route object" << endl;
  cout << "\t -Key data that we will be using from this dataset will be:" << endl;
  cout << "\t -Departure Iata Code," << endl;
  cout << "\t -Destination Iata Code" << endl;
  cout << "\n _______________________________ Parsing Data _______________________________" << endl;
  cout << "\n";
  cout << "Our data is parsed in each of their own respective objects" << endl;
  cout << "\t -Destination and Route Iata codes are each stored in seperate vectors with each index representing the full route" << endl;
  cout << "\t -The rest of the data is stored as private data members of each object" << endl;
  cout << "\n _______________________________ Adjacency List _______________________________" << endl;
  cout << "\n";
  cout << "Our adjacency list is represented as a map from an airport to a vector of pairs of Airports and doubles" << endl;
  cout << "\t -The vector value represents all the adjacencies from the key Airport" << endl;
  cout << "\t -At the first index of the pair includes another Airport, which resembles the destination from the key value Airport" << endl;
  cout << "\t -At the second index of the pair includes a double, which is the distance between both airports," << endl;
  cout << "\t -This distance is calculated by taking the coordinates of both airports, and calculating the Euclideans Distance from both of them" << endl;
  cout << "\n";
  cout << "- The reason for this specific implementation is to optimize code efficiency," << endl;
  cout << "- Creating a simple map from airport to airport will accomplish the same goal however would require several more data structures relating to distance and other adjacencies " << endl;
  cout << "- This implementation allows the code to be more neatly shown and lessens the variables to keep track of" << endl;
  cout << "\n";
  cout << "\n _______________________________ BFS Implentation _______________________________" << endl;
  cout << "\n";
  cout << "Our BFS implementation uses our adjacency list to traverse through values in each Graph Component" << endl;
  cout << "Calling BFS on one specific Airport will traverse through the full network of nodes and edges of the Graph Component it belongs to" << endl;
  cout << "\n";
  cout << "Our function num_connectedComponents(), returns the number of connected components our dataset includes" << endl;
  cout << "\n";
  cout << "It accomplishes this by calling BFS on each index of the airports class " << endl;
  cout << "\t -This may seem inefficient at first, however our implementation includes a map from Airport to bool which constitutes as our visited" << endl;
  cout << "\t -Whenever BFS is called, it populates the global variable visited, which means each mapping will not be visited more than once " << endl;
  cout << "\t -This means that BFS will only be called once per graph component " << endl; 
  cout << "\n";
  cout << "Our BFS implementation can be tested by calling our printComponentSizes() function" << endl;
  cout << "\n";
  std::cout << "\t Number of Connected Components: " << a.num_connectedComponents() << std::endl;
  a.printComponentSizes(3);
  cout << "\n";
  cout << "\n _______________________________ Page Rank Implentation _______________________________" << endl;
  cout << "\n";
  cout << "Our project includes a Page Rank Algorithm to determine the most important airports " << endl;
  cout << "- We used the map data structure to hold a Airport, and a double to represent points" << endl;
  cout << "- Each airport is initialized with the same amount of points, that being 1/n where n is the number of airports" << endl;
  cout << "- Then, we iterate through each of the airports adjacency vectors to add a value 1/n to their points, where n is the number of adjacencies in the airport of the ith term " << endl;
  cout << "- We also multiplied the points by a decay value of 0.8 each time something is being added to ensure we dont get a ranking of just most visited airports" << endl;
  cout << "\n" << endl;
  cout << "This implementation resulted in a full mapping of each airport to a value of points, where the points resemble its importance" << endl;
  cout << "We can now rank the top n amount of Airports with our function printAirportRanking(n)" << endl;
  a.printAirportRanking(5, true);
  cout << "\n _______________________________ Dijkstra's Implementation _______________________________" << endl;
  cout << "\n";
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
