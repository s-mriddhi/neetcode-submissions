class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector <vector<int>> adjList(numCourses);
        vector <vector<bool>> dp(numCourses, vector<bool>(numCourses,false));
        //Mark the base cases as true
        for(auto p: prerequisites){
            adjList[p[0]].push_back(p[1]);
            dp[p[0]][p[1]] = true;
        }

        
       
        for(int k =0; k<numCourses; k++){
            for(int i = 0; i<numCourses; i++){
                for(int j = 0; j<numCourses; j++){
                    dp[i][j] = (dp[i][j])||(dp[i][k]&&dp[k][j]);
                }
            }
        }

        vector <bool> ans;
        for(auto q: queries){
            ans.push_back(dp[q[0]][q[1]]);
        }

        return ans;
    }
};