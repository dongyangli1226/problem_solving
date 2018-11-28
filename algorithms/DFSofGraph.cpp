
#include <iostream>
#include <vector>
#include <queue>

class Graph{
    int V; //number of vertices

    std::vector<int> *adjacencyList;

public:
    Graph(int V); //constructor

    void addEdge(int v, int w);

    void printDFSUtil(int start, std::vector<bool>& visited);
    void printDFS(int start);

};

Graph::Graph(int V){
    this->V = V;
    this->adjacencyList = new std::vector<int>[V];
}

void Graph::addEdge(int v, int w){
    this->adjacencyList[v].push_back(w);
}

void Graph::printDFSUtil(int start, std::vector<bool>& visited){
    visited[start] = true;
    std::cout << start << " ";

    for(int i=0; i<adjacencyList[start].size(); i++){
        if(!visited[adjacencyList[start][i]]){
            visited[adjacencyList[start][i]] = true;
            printDFSUtil(adjacencyList[start][i], visited);
        }
    }
}

void Graph::printDFS(int start){
    std::vector<bool> visited(this->V, false);

    printDFSUtil(start, visited);
}

int main(){

    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    std::cout << "Breadth First Traversal starting from vertex 2 \n"; 
    g.printDFS(2);
    std::cout << std::endl;
    
    return 0; 
}