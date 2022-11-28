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

class Graph
{
public:
  
    Graph(bool weighted);
    //Graph(bool weighted, bool directed);
    //Graph(bool weighted, int numVertices);


    vector<Vertex> getAdjacent(Vertex source) const;
    
    Vertex getStartingVertex() const;

    bool vertexExists (Vertex v) const;
    void insertVertex(Vertex v);
    Vertex removeVertex(Vertex v);


    //EDGE FUNCTIONS
    bool insertEdge(Vertex start, Vertex dest);
    Edge removeEdge(Vertex start, Vertex dest);

    Edge setEdgeWeight(Vertex start, Vertex dest, unsigned weight);

    bool edgeExists(Vertex source, Vertex destination) const;

    Edge setEdgeLabel(Vertex source, Vertex destination, string label);
    string getEdgeLabel(Vertex source, Vertex destination) const;

    unsigned getEdgeWeight(Vertex start, Vertex dest) const;
    Edge getEdge(Vertex source, Vertex destination) const;

private:

    //Adjenaccy list representation of a graph 
    mutable unordered_map<Vertex, unordered_map<Vertex, Edge>> adj_list;

};