class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector <vector<int>> adjList(n);
        vector <unordered_set<int>> pre_req(n);
        for(auto p : prerequisites){
            adjList[p[0]].push_back(p[1]);
        }
        vector <int> indegree(n,0);
        for(auto node: adjList){
            for(auto adjNode : node){
                indegree[adjNode]++;
            }
        }
       
        queue <int> q;
        for(int i = 0; i<n ; i++){
            if(indegree[i]==0){
                q.push(i);
                // this covers even disconnected components
            }
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            for(auto adj : adjList[top]){
                pre_req[adj].insert(top);
                pre_req[adj].insert(pre_req[top].begin(),pre_req[top].end());
                indegree[adj]--;
                if(!indegree[adj]){
                    
                    q.push(adj);
                }
            }
        }
    vector <bool> ans;
        for(auto q: queries){
            bool res = (pre_req[q[1]].count(q[0])!=0);
            ans.push_back(res);
        }

        return ans;
    }
};