#pragma once
#include "Routes.h"
#include "Airport.h"
#include <list>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
#include <fstream>
#include <iostream>


using namespace std;
class Graph
{
public:
    Graph();
    void createGraph();
    unordered_map<int, vector<int>> getGraph();

    void EdgeWeights();
    double calculateDistance(double latFrom, double longFrom, double latTo, double longTo);



    //Airport
     Airport a;
    int num_airports = a.get_airports().size();
    std::vector<Airport>  airport_arr = a.get_airports();

    //Route
    Route r;
    vector<int> starting = r.getSourceVect();
    vector<int> ending = r.getDestVect();


private:

    //Adjenaccy list representation of a graph 
    unordered_map<int, vector<int>> adjacencyList;

    //vector of Lat, Long of each route
    vector<pair<double,double>> coordinates;
};













    // Graph(bool weighted);
    // //Graph(bool weighted, bool directed);
    // //Graph(bool weighted, int numVertices);


    // vector<Vertex> getAdjacent(Vertex source) const;
    
    // Vertex getStartingVertex() const;

    // bool vertexExists (Vertex v) const;
    // void insertVertex(Vertex v);
    // Vertex removeVertex(Vertex v);


    // //EDGE FUNCTIONS
    // bool insertEdge(Vertex start, Vertex dest);
    // Edge removeEdge(Vertex start, Vertex dest);

    // Edge setEdgeWeight(Vertex start, Vertex dest, unsigned weight);

    // bool edgeExists(Vertex source, Vertex destination) const;

    // Edge setEdgeLabel(Vertex source, Vertex destination, string label);
    // string getEdgeLabel(Vertex source, Vertex destination) const;

    // unsigned getEdgeWeight(Vertex start, Vertex dest) const;
    // Edge getEdge(Vertex source, Vertex destination) const;