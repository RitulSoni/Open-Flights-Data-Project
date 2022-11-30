#include "Graph.h"
#include "Airport.h"
#include "Routes.h"
#include <cmath>

using namespace std;

Graph::Graph(){}


void Graph::createGraph() {


   
    cout << num_airports << std::endl;

    for (auto i = 0; i < num_airports; ++i) {

        if (adjacencyList.find(airport_arr[i].get_AirportId()) == adjacencyList.end()) {
            vector<int> temp;
            adjacencyList.insert(pair<int, vector<int>>(airport_arr[i].get_AirportId(), temp));
        }
    }


    for (size_t i = 0; i < starting.size(); ++i) {
        if (adjacencyList.find(starting[i]) != adjacencyList.end() && adjacencyList.find(ending[i]) != adjacencyList.end()) {
            adjacencyList[starting[i]].push_back(ending[i]);
        }
    }

}

unordered_map<int, vector<int>> Graph::getGraph() {
    return adjacencyList;
}


void Graph::EdgeWeights() {
   
   //populate the cooridnates vector with each coordiante of each airport
    // for (int i = 0; i < num_airports; ++i) {
    //     coordinates.push_back(airport_arr[i].get_AirportCoordinates());
    // }

    // //traverse through starting airports and push back each route int
    // for (int i = 0; i < starting.size(); ++i) {
    //     vector<int> temp;
    //     temp.push_back(starting[i]);
    //     temp.push_back(ending[i]);

    //     if (coordinates[i].first.find(starting[i]) != coordinates[i].first.end() && coordinates[i].first.find(ending[i]) != coordinates[i].first.end()) {
    //         if (coordinates[i].second.find(starting[i]) != coordinates[i].second.end() && coordinates[i].second.find(ending[i]) != coordinates[i].second.end()) {
    //             double weight = calculateDistance(coordinates[i].first[from[i]], coordinates[i].second[from[i]], coordinates[i].first[ending[i]], coordinates[i].second[ending[i]]);
    //             edgesLabel.insert(pair<vector<int>, double>(temp, weight));
    //         }
    //     }
    // }
}


double Graph::calculateDistance(double start_x, double start_y, double end_x, double end_y) {
    return sqrt(((start_x - start_y) * (start_x - start_y)) + ((end_x - end_y) * (end_x - end_y)));
}