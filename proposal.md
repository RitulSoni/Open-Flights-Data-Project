## Leading Question 
Given the OpenFlights Dataset, our project will implement algorithms to show us statistics such as most popular destinations, airports, and a function which takes multiple inputs and outputs the most optimal route. Some algortithms that would helps us accomplish this would include Breath First Search and Dijkstra's algortihm using an adjacency list representation of a graph, with each edge between nodes have a weight of the distance between two locations

## Dataset Acquisition

https://openflights.org/data.html

    
## Data Format

 Our group will be using the OpenFlights data set. This is a database which provides information from over 10,000 airports, train stations, and ferry terminals across the world. There are several data sets available, however our group will only be using the one which is limited to Airports Only.

## Data Correction

Data is separated through commas, like so            

    507,"London Heathrow Airport","London","United Kingdom","LHR","EGLL",51.4706,-0.461941,83,0,"E","Europe/London","airport","OurAirports"
    
 We will parse through this information with CSV file standards. Our group will make sure the integrity of our data is perfect using the resources that OpenFlights provides. We will implement multiple checks at every single index to ensure that there are no missing data, and also no outliers.

## Data Storage

Our project will use an adjacency list representation of a Weighted Graph in order to store the information of all the airports with each index describing a different aspect of the dataset. The value of each edge will be calculated as the distance between the two nodes (airports) and mapped accordingly. To accomplish our goals the upper bound on storage costs would be O(n+m), which is faster than the alternative of a adjacency matrix.

## Algorithm 

Our project will use a weighted graph implementation using a map as an adjacency list, which will hold nodes as airports and routes as edges. We plan to use a BFS traversal to visit the whole graph structure. For the implementation of our function we plan to use Dijkstra's algortihm to find the most efficient route between two nodes. This will take in two nodes, one a departure, and the other a destination, and will return an edge which would be the most efficient route. This will be accomplished by traversing through all the edges between two specific nodes, and returning which one has the lowest weight which will be the lowest distance. Dijkstra's algorithm directly correlates to this function which is the reason for its implementation in our project. Time complexities for Dijkstra's algorithm would be O(E Log(V)) using an adjencency matrix of a graph where V is the number of verticies and E is the number of edges. With the worst case being a O(V^2) brute force implementation of Dijktra's algorthim

In order to accomplish our goal in finding the most popular airports, we would like to use an algorithm similar to what google uses (PageRank). This would give each node a rating of importance and output which are the top ranks. Since PageRank must touch every edge more than once, it would give us O(n + m) runtime. 

## Timeline

Below includes our timeline estimates of when our group would accomplish core tasks. 

November 8th - Data Acquisition

November 12th - Data Processing 

November 15th - Algorithm implementations

November 25th - Production of final deliverables 


