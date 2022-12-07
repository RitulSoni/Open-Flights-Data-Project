# CS225 Final Project 



<a name="readme-top"></a>





<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#introduction">Introduction</a></li>
      </ul>
    </li>
    <li>
      <a href="#technical-architecture">Technical Architecture</a>
      <ul>
        <li><a href="#components">Components</a></li>
        <li><a href="#diagram">Diagram</a></li>
      </ul>
    </li>
    <li><a href="#installation-and-usage">Installation and Usage</a></li>
    <li><a href="#group-members-and-their-roles">Group members and their roles</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>

## About the Project

### Introduction
Our project uses the OpenFlights data set, where we get access to thousands of airports, routes, and data. We took this data and cleaned it to give us the pertinent data subset need to created a Graph of connected airports and routes. We used an adjacency list representation of a weighted graph to be able to run in optimal runtimes which will be discussed below. Users are able to run various simple command line commands to run the various algorthims we created to find the shortest path from one airport to another, to find the busiest airports, and also see the number of aiports who are connected together in a single component.  



## Installation and Usage

1. Clone the repo:
   ```sh
   git clone https://github.com/RitulSoni/CS225-Final-Project.git
   ```
2. Change directory into the `CS225-Final-Project` folder:
    ```sh
    cd CS225-Final-Project
    ```
3. Change directory into the `build` folder:
    ```sh
    cd build
    ```
      
4. In the `build` directory, "run cmake .."
   ```sh
   cmake ..
   ```
5. In the `build` directory, run make test && ./test to make sure all tests are passing
   ```sh
    make test && ./test
   ```
6. To see the output run make main && ./main  
    ```sh
   make main && ./main
    ```    


## Technical Architecture

[![React][React.js]][React-url] [![JavaScript][JavaScript]][JavaScript-url] [![TensorFlowJs][TensorFlowJS]][TensorFlowJS-url]

Our project utilizes React with JavaScript frontend, Express as a backend, and TensorFlowJS for the model.

### Diagram


![image](images/ArchitectureDiagram.png)

### Backend
***

#### Graph Implementation 

The OpenFlights dataset contains information about airports and the routes between them. An adjacency list representation of a graph can be used to store this data by representing each airport as a vertex in the graph and each route between airports as an edge in the graph.

To create the adjacency list, we would first need to parse the dataset and extract the information about the airports and routes. We would then create a vertex for each airport and add it to the adjacency list. For each route in the dataset, we would add an edge to the adjacency list that connects the vertices representing the source and destination airports.

Once the adjacency list has been constructed, it can be used to answer various questions about the airports and routes in the dataset. For example, we could use the adjacency list to find the shortest path between two airports, or to compute the connected components of the graph to see which airports are reachable from each other. The adjacency list would also allow us to efficiently store and access the data from the OpenFlights dataset.

#### Adjacency List vs. Adjacency Matrix

An adjacency list is a way of representing a graph G = (V, E) as a list of the vertices V adjacent to each vertex in V. This is typically implemented as a list of linked lists. An adjacency matrix is a matrix-based representation of a graph where the entry at the ith row and jth column is 1 if there is an edge between vertex i and vertex j and 0 otherwise.

One key difference between the two representations is the amount of memory they use. An adjacency matrix uses O(V^2) memory to represent a graph with V vertices, while an adjacency list uses O(V + E) memory, where E is the number of edges in the graph. This means that for graphs with a large number of vertices and a small number of edges, an adjacency list may use significantly less memory than an adjacency matrix.

Another difference is the time complexity of common operations on the two representations. For example, checking whether there is an edge between two vertices in a graph with an adjacency matrix takes O(1) time, since you can simply look up the value in the matrix at the corresponding row and column. In contrast, checking for the existence of an edge in a graph with an adjacency list takes O(deg(v)) time, where deg(v) is the degree of the vertex v (i.e., the number of edges incident to v). This is because you need to traverse the linked list for vertex v to see if the other vertex is present in the list.

Overall, the choice between using an adjacency list or an adjacency matrix to represent a graph depends on the specific characteristics of the graph and the operations you want to perform on it. In general, adjacency lists are more memory-efficient and are better suited for graphs with a large number of vertices and a small number of edges, while adjacency matrices are faster for checking the presence of edges and are better suited for graphs with a small number of vertices and a large number of edges.

### Algorthims & Runtimes
***

#### Djsktra's Algorthim 
Dijkstra's algorithm is a graph search algorithm that solves the single-source shortest path problem for a graph with non-negative edge weights, producing a shortest-path tree. This algorithm is often used in routing and as a subroutine in other graph algorithms.

The algorithm works by maintaining a set of distances from the source vertex to all other vertices in the graph. At each step, the algorithm picks the vertex that is not in the set of visited vertices and has the minimum distance from the source vertex. The distance to this vertex is then updated to reflect the fact that we have found a shorter path to it. This process is repeated until the distances to all vertices have been determined.

#### Breadth-First Search
Breadth-first search (BFS) is an algorithm for traversing or searching a graph data structure. It starts at a given vertex and explores all the neighboring vertices before moving to the next level neighbors. The purpose of BFS is to compute the shortest path between a starting vertex and all other vertices reachable from it.

BFS can be used to solve a variety of problems in graph theory, including finding the shortest path between two vertices, computing the connected components of a graph, and generating a spanning tree of a graph. It can also be used as a subroutine in other graph algorithms, such as cycle detection and topological sorting. BFS has a time complexity of O(V + E), where V is the number of vertices and E is the number of edges in the graph.

#### Depth-First Search

Depth-first search (DFS) is an algorithm for traversing or searching a graph data structure. It starts at a given vertex and explores as far as possible along each branch before backtracking. The purpose of DFS is to traverse the entire graph, or to visit all the vertices and edges of a graph in a particular manner.

DFS can be used to solve a variety of problems in graph theory, including finding connected components in a graph, testing if a graph is bipartite, and finding the strongly connected components of a directed graph. It can also be used as a subroutine in other graph algorithms, such as topological sorting and cycle detection.

DFS has a time complexity of O(V + E), where V is the number of vertices and E is the number of edges in the graph. Additionally, DFS only visits vertices that are reachable from the starting vertex, so it may not find the shortest path between two vertices if the graph has multiple connected components.

#### Page Rank

In a graph, the PageRank of a vertex is calculated based on the PageRanks of the vertices that link to it. This creates a system where vertices with a high PageRank are considered more important than vertices with a low PageRank. The PageRank of a vertex can be used to measure the importance or centrality of the vertex in the graph.



## Group Members and Their Roles

[Kazmain Shah](https://github.com/kazshah23) worked with creating the weighted adjacency list of a graph

[Ritul K. Soni](https://github.com/RitulSoni) worked with creating the algorthims neccessary to reach our output. Implemented Djktras, Breadth First Search, Depth First Search, and Page Rank Algorthims. Also created test cases and the cmake compatability. 

[Keshav Trikha](https://github.com/ktrikha2) worked with Data Cleaning and parsing with the OpenFlights dataset to seperate the data by the elements we need to create teh graph. 


## Acknowledgements
Thank you to the OpenFlights open source data set and our mentor Mona!

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- Links & Images -->
[contributors-shield]: https://img.shields.io/github/contributors/CS222-UIUC/course-project-group-97.svg?style=for-the-badge
[contributors-url]: https://github.com/CS222-UIUC/course-project-group-97/graphs/contributors
[stars-shield]: https://img.shields.io/github/stars/CS222-UIUC/course-project-group-97.svg?style=for-the-badge
[stars-url]: https://github.com/CS222-UIUC/course-project-group-97/stargazers
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[JavaScript]:https://img.shields.io/badge/JavaScript-JS-yellowgreen
[JavaScript-url]: https://www.javascript.com
[TensorFlowJs]: https://img.shields.io/badge/TensorFlow-TensorFlow.js-blue
[TensorFlowJs-url]: https://www.tensorflow.org



