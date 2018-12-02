//detect if there is a cycle in a graph
//implementation from geeksforgeeks, more C++ style

#include <iostream>
#include <vector>

struct Edge{
    int src;
    int des;
};

struct Graph{
    int V;
    int E;
    std::vector<Edge> edge;
};

Graph createGraph(int V, int E){
    Graph graph;
    graph.V = V;
    graph.E = E;
    std::vector<Edge> edge(E);
    graph.edge = edge;

    return graph;
}

// function to find the subset of element v
int find(std::vector<int> parent, int v)
{ 
    if (parent[v] == -1) 
        return v; 
    return find(parent, parent[v]); 
}

// function to union two subsets
void unionSubsets(std::vector<int> parent, int x, int y){
    int xSet = find(parent, x);
    int ySet = find(parent, y);

    if(xSet != ySet){
        parent[xSet] = ySet;
    }
}

bool containsCycle(Graph graph){
    std::vector<int> parent(graph.V, -1);

    for(int i=0; i<graph.E; i++){
        int x = find(parent, graph.edge[i].src);
        int y = find(parent, graph.edge[i].des);

        if(x == y){
            return true;
        }

        unionSubsets(parent, x, y);
    }
}

int main() 
{ 
    /* Let us create following graph 
         0 
        |  \ 
        |    \ 
        1-----2 */     
    int V = 3, E = 3; 
    Graph graph = createGraph(V, E); 
  
    // add edge 0-1 
    graph.edge[0].src = 0; 
    graph.edge[0].des = 1; 
  
    // add edge 1-2 
    graph.edge[1].src = 1; 
    graph.edge[1].des = 2; 
  
    // add edge 0-2 
    graph.edge[2].src = 0; 
    graph.edge[2].des = 2; 
  
    if (containsCycle(graph)) 
        printf( "graph contains cycle" ); 
    else
        printf( "graph doesn't contain cycle" );

    std::cout << std::endl;
  
    return 0; 
} 