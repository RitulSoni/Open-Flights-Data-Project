#pragma once

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


private:

    //Adjenaccy list representation of a graph 
    unordered_map<int, vector<int>> adjacencyList;
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