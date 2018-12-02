//algorithm to find all shortest paths to all vertices for each vertex

#include <iostream>
#include <vector>
#include <climits>

std::vector<std::vector<int> > findAllShortestPaths(std::vector<std::vector<int> > graph){
    std::vector<std::vector<int>> dist = graph;

    int V = graph.size();
    
    for(int k=0; k<V; k++){

        // Pick all vertices as source each time
        for(int i=0; i<V; i++){

            // Pick all vertices as destination for the above picked source
            for(int j=0; j<V; j++){

                // If vertex k is on the shortest path from i to j
                // then update distance from i to j
                // dist[i][k] != INT_MAX && dist[k][j] != INT_MAX is used to avoid overflow
                
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}

int main(){
    std::vector<std::vector<int> > graph = {{0,   5,  INT_MAX, 10}, 
                                            {INT_MAX, 0,   3, INT_MAX}, 
                                            {INT_MAX, INT_MAX, 0,   1}, 
                                            {INT_MAX, INT_MAX, INT_MAX, 0} 
                                            }; 

    std::vector<std::vector<int>> dist = findAllShortestPaths(graph);

    for(int i=0; i<graph.size(); i++){
        for(int j=0; j<graph.size(); j++){
            std::cout << dist[i][j] << " ";
        }

        std::cout << std::endl;
    }
}