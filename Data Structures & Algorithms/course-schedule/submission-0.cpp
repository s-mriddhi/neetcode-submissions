class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector <vector<int>> adjList(n);
        for(auto p : prerequisites){
            adjList[p[0]].push_back(p[1]);
        }
        vector <int> indegree(n,0);
        for(auto node: adjList){
            for(auto adjNode : node){
                indegree[adjNode]++;
            }
        }
        vector <int> result;
        queue <int> q;
        for(int i = 0; i<n ; i++){
            if(indegree[i]==0){
                q.push(i);
                result.push_back(i); // this covers even disconnected components
            }
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            for(auto adj : adjList[top]){
                indegree[adj]--;
                if(!indegree[adj]){
                    result.push_back(adj);
                    q.push(adj);
                }
            }
        }
        
        return result.size()==n;
    }
};
