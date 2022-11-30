#include "Graph.h"
#include "Airport.h"
#include "Routes.h"

using namespace std;

Graph::Graph(){}


void Graph::createGraph() {


    Airport a;
    int num_airports = a.get_airports().size();
    auto airport_arr = a.get_airports();
    cout << num_airports << std::endl;

    for (auto i = 0; i < num_airports; ++i) {

        if (adjacencyList.find(airport_arr[i].get_AirportId()) == adjacencyList.end()) {
            vector<int> temp;
            adjacencyList.insert(pair<int, vector<int>>(airport_arr[i].get_AirportId(), temp));
        }
    }

    Route r;
    vector<int> starting = r.getSourceVect();
    vector<int> ending = r.getDestVect();

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
    Route r;
    vector<int> starting = r.getSourceVect();
    vector<int> ending = r.getDestVect();

    for (int i = 0; i < (int) from.size(); i++) {
        vector<int> temp;
        temp.push_back(starting[i]);
        temp.push_back(ending[i]);
        
        if (latitudes.find(from[i]) != latitudes.end() && latitudes.find(to[i]) != latitudes.end()) {
            if (longitudes.find(from[i]) != longitudes.end() && longitudes.find(to[i]) != longitudes.end()) {
                double weight = calculateDistance(latitudes[from[i]], longitudes[from[i]], latitudes[to[i]], longitudes[to[i]]);
                edgesLabel.insert(pair<vector<int>, double>(temp, weight));
            }
        }
    }
}