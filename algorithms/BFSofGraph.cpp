
#include <iostream>
#include <vector>
#include <queue>

class Graph{
    int V; //number of vertices

    std::vector<int> *adjacencyList;

public:
    Graph(int V); //constructor

    void addEdge(int v, int w);

    void printBFS(int start);

};

Graph::Graph(int V){
    this->V = V;
    this->adjacencyList = new std::vector<int>[V];
}

void Graph::addEdge(int v, int w){
    this->adjacencyList[v].push_back(w);
}

void Graph::printBFS(int start){
    std::vector<bool> visited(this->V, false);

    std::queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        start=q.front();
        std::cout << start << " ";
        q.pop();

        for(int i=0; i<adjacencyList[start].size(); i++){
            if(!visited[adjacencyList[start][i]]){
                visited[adjacencyList[start][i]] = true;
                q.push(adjacencyList[start][i]);
            }
        }
    }
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
    g.printBFS(2);
    std::cout << std::endl;
    
    return 0; 
}