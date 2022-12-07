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
