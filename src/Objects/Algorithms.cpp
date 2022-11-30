#include "Algorithms.h"
#include "Airport.h"
#include "Graph.h"

// Returns the order of airports 
std::vector<int> Algorithms::BFS(int source) {
  Airport a;
  std::vector<int> output;
  std::vector<bool> visited(17000, false);
  Graph g;
  auto adj_list = g.getGraph();
  std::queue<int> queue;
  queue.push(source);
  int curr = source;

  while (!queue.empty()) {
    curr = queue.front();
    if (visited[curr]) {
      queue.pop();
      continue;
    }
    for (int adj : adj_list[curr]) {
      queue.push(adj);
    }
    visited[curr] = true;
    output.push_back(curr);
    queue.pop();
  }
  return output;
}