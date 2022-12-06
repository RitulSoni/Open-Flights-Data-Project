#include "Algorithms.h"


// using namespace std;
Algorithms::Algorithms(){
  
}
// Returns the order of airports 
std::vector<Airport> Algorithms::BFS(Airport air) {
  vector<Airport> output;
  map<Airport, bool> visited;
  queue<Airport> queue;
  queue.push(air);
  Airport curr = air;
  a.build_edge();
  std::map<Airport, std::vector<std::pair<Airport, double>>> adj_list = a.get_adjList();
 
  while (!queue.empty()) {
    curr = queue.front();
    if (visited[curr]) {
      queue.pop();
      continue;
    }
    for (std::pair<Airport, double> air : adj_list[curr]) {
      queue.push(air.first);
    }
    visited[curr] = true;
    output.push_back(curr);
    queue.pop();
    visited.insert({air, true});
  }
  return output;
}

// Given two airports, find the distance between both 
double Algorithms::distanceBetween(Airport air1 , Airport air2) {
  a.build_edge();
  std::map<Airport, std::vector<std::pair<Airport, double>>> adj_list = a.get_adjList();
  for (std::pair<Airport, double> air : adj_list[air1]) {
    if (air2.get_AirportIATA() == air.first.get_AirportIATA()) return air.second;
  }
  return -1;
}




