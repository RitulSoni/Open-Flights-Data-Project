#include "Graph.h"
#include "Airport.h"

using namespace std;


// void Graph::createGraph() {


//     Airport a;
//     int num_airports = a.get_airports().size();
//     auto airport_arr = a.get_airports();
//     cout << num_airports << std::endl;

//     for (auto i = 0; i < num_airports; ++i) {

//         if (adjacencyList.find(airport_arr[i]) == adjacencyList.end()) {
//             vector<int> temp;
//             adjacencyList.insert(pair<int, vector<int>> (airport_arr[i], temp));
//         }
//     }


//     for (int i = 0; i < (int) from.size(); i++) {
//         if (adjacencyList.find(from[i]) != adjacencyList.end() && adjacencyList.find(to[i]) != adjacencyList.end()) {
//             adjacencyList[from[i]].push_back(to[i]); //routes are directional
//         }
//     }

// }