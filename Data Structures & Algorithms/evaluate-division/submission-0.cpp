
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Step 1: Assign a unique integer ID to each string variable
        unordered_map<string, int> stringToId;
        int idCounter = 0;
        
        for (const auto& eq : equations) {
            if (!stringToId.count(eq[0])) stringToId[eq[0]] = idCounter++;
            if (!stringToId.count(eq[1])) stringToId[eq[1]] = idCounter++;
        }

        // Step 2: Build the normal vector-based adjacency list
        // adj[u] stores pairs of {v, weight} where u and v are integer IDs
        vector<vector<pair<int, double>>> adj(idCounter);

        for (int i = 0; i < equations.size(); i++) {
            int u = stringToId[equations[i][0]];
            int v = stringToId[equations[i][1]];
            double val = values[i];
            
            adj[u].emplace_back(v, val);
            adj[v].emplace_back(u, 1.0 / val);
        }

        // Step 3: Evaluate queries using integer IDs
        vector<double> res;
        res.reserve(queries.size());
        
        for (const auto& query : queries) {
            string srcStr = query[0];
            string targetStr = query[1];
            
            // If either variable wasn't in equations, the calculation is impossible
            if (!stringToId.count(srcStr) || !stringToId.count(targetStr)) {
                res.push_back(-1.0);
            } else {
                int srcId = stringToId[srcStr];
                int targetId = stringToId[targetStr];
                res.push_back(bfs(srcId, targetId, adj, idCounter));
            }
        }

        return res;
    }

private:
    // BFS now operates entirely on integer IDs and uses a vector for track tracking visited nodes
    double bfs(int src, int target, const vector<vector<pair<int, double>>>& adj, int numNodes) {
        queue<pair<int, double>> q;
        // Fast vector-based boolean array instead of an unordered_set
        vector<bool> visited(numNodes, false);
        
        q.emplace(src, 1.0);
        visited[src] = true;

        while (!q.empty()) {
            auto [node, weight] = q.front();
            q.pop();

            if (node == target) {
                return weight;
            }

            for (const auto& [nei, neiWeight] : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.emplace(nei, weight * neiWeight);
                }
            }
        }

        return -1.0;
    }
};
