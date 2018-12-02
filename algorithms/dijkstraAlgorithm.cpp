//algorithm to find shortest path from a source to every vertex
// used adjacency matrix , O(V^2)
// it can be improved by using adjacency list and binary heap O(ElogV)

#include <iostream>
#include <vector>
#include <climits>

const int V = 9;

int minDistanceVertex(std::vector<bool> sptSet, std::vector<int> dist){
    int minDist = INT_MAX;
    int minVertex;

    for(int v=0; v<V; v++){
        if(!sptSet[v] && dist[v] < minDist){
            minDist = dist[v];
            minVertex = v;
        }
    }

    return minVertex;
}

std::vector<int> findShortestPaths(std::vector<std::vector<int>> graph, int src){
    std::vector<bool> sptSet(V, false); //shortest path tree Set
    std::vector<int> dist(V, INT_MAX);

    dist[src] = 0; //starting vertex

    //find shortest paths for all other 8 vertices
    for(int count=0; count < V-1; count++){

        //the first u will always be src
        int u = minDistanceVertex(sptSet, dist);
        sptSet[u] = true;

        for(int v=0; v<V; v++){
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist;
}

int main(){
    std::vector<std::vector<int>> graph =   {
                                            {0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                                            {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                                            {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                                            {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                                            {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                                            {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                                            {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                                            {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                                            {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                                            }; 

    std::vector<int> dist=findShortestPaths(graph, 0);

    for(auto i : dist){
        std::cout << i << std::endl;
    }

    return 0;
}