class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // check number of edges = v - 1 first
        // then check for no cycle
        int e = edges.size();
        if(e != n - 1) return false;
        // check for no cycle
        // no need to check for , if tree, therre will be just one
        vector <vector<int>> adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int seenNode= 0;

        vector <bool> vis(n ,false);
        return (!hasCycle(0, -1, adj, vis, seenNode) && seenNode==n);
    }

    bool hasCycle(int node, int par, vector <vector<int>> &adj,  vector <bool> &vis, int& seenNode){
        vis[node] = true;
        seenNode++;
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                  if(hasCycle(adjNode, node, adj, vis, seenNode)) return true;
            }
            else{
                if(adjNode != par) return true;
            }
        }
        return false;
    }
};
