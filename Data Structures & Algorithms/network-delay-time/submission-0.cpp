class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create an adjacency list
        vector<vector<vector<int>>> adjList(n+1);
        for(auto time: times){
            adjList[time[0]].push_back({time[1], time[2]});
            // Directed
        }
        vector <int> dist(n+1, INT_MAX);
        typedef pair<int, int> pi;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int dis = top.first;
            int src = top.second;
            if(dist[src] < dis) continue;
            for(auto adj : adjList[src]){
                int v = adj[1];
                if(dist[adj[0]]> dis + v){
                    dist[adj[0]] = dis + v;
                    pq.push({dis + v, adj[0]});
                }
            }
        }

        int maxi = 0;
        for(int i =1; i<dist.size(); i++){
            maxi = max(maxi, dist[i]); 
        }

        if(maxi==INT_MAX) return -1;
        return maxi;
    }
};
