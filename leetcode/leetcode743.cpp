//network delay time

#include <vector>
#include <climits>

//Bellman - Ford
int networkDelayTime(std::vector<std::vector<int>>& times, int N, int K) {
    if(times.empty()){
        return -1;
    }

    std::vector<int> dp(N+1, INT_MAX);
    dp[K] = 0;

    int u, v, w;

    for(int i=1; i<=N; i++){
        for(int j=0; j<times.size(); j++){
            u = times[j][0];
            v = times[j][1];
            w = times[j][2];

            //if dp[u] has already been visited and distance u to v is smaller than previous
            if(dp[u] != INT_MAX && dp[v] > dp[u] + w){
                dp[v] = dp[u] + w;
            }
        }
    }

    int res=0;
    for(int i=1; i<=N; i++){
        if(dp[i] == INT_MAX){
            return -1;
        }
        res = std::max(res, dp[i]);
    }

    return res;
}