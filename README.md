# Open Flights Data Project



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
3. Make the `build` directory :
    ```sh
    mkdir build
    ```
4. Change directory into the `build` folder:
    ```sh
    cd build
    ```
5. In the `build` directory, "run cmake .."
   ```sh
   cmake ..
   ```
6. In the `build` directory, run make test && ./test to make sure all tests are passing
   ```sh
    make test && ./test
   ```
7. To see the output and breakdown of the code run make main && ./main  
    ```sh
   make main && ./main
    ```    


## Technical Architecture



#### Graph Implementation 

The OpenFlights dataset contains information about airports and the routes between them. An adjacency list representation of a graph can be used to store this data by representing each airport as a vertex in the graph and each route between airports as an edge in the graph.

To create the adjacency list, we would first need to parse the dataset and extract the information about the airports and routes. We would then create a vertex for each airport and add it to the adjacency list. For each route in the dataset, we would add an edge to the adjacency list that connects the vertices representing the source and destination airports.

Once the adjacency list has been constructed, it can be used to answer various questions about the airports and routes in the dataset. For example, we could use the adjacency list to find the shortest path between two airports, or to compute the connected components of the graph to see which airports are reachable from each other. The adjacency list would also allow us to efficiently store and access the data from the OpenFlights dataset.








## Group Members and Their Roles

[Kazmain Shah](https://github.com/kazshah23) worked with creating the weighted adjacency list of a graph, and creating the algorthims neccessary to reach our output. Implemented Breadth First Search, Depth First Search and Page Rank Algorithms. Also created Test Cases for each data structure and function, and created the project description in main.cpp.

[Ritul K. Soni](https://github.com/RitulSoni) Implemented algorithms including Page Rank, developed the Adjacency List representation of a graph for teh Open Flights Data Set, and worked with CMAKE compatability.

[Keshav Trikha](https://github.com/ktrikha2) worked with Data Cleaning and parsing with the OpenFlights dataset to seperate the data by the elements we need to create the graph. Created the Dijkstras algorithm to find the smallest route between two airports

## Link to Presentation Video
https://mediaspace.illinois.edu/media/t/1_31cad32r

## Acknowledgements
Thank you to the OpenFlights open source data set and our mentor Mona!

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- Links & Images -->
[contributors-shield]: https://img.shields.io/github/contributors/CS222-UIUC/course-project-group-97.svg?style=for-the-badge
[contributors-url]: https://github.com/CS222-UIUC/course-project-group-97/graphs/contributors
[stars-shield]: https://img.shields.io/github/stars/CS222-UIUC/course-project-group-97.svg?style=for-the-badge
[stars-url]: https://github.com/CS222-UIUC/course-project-group-97/stargazers




