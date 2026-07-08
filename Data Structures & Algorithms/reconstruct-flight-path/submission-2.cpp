class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map <string, vector<string>> mp;
        for(auto tic : tickets){
            mp[tic[0]].push_back(tic[1]);
        }
        vector <string> result;
        for(auto &[src, dests] : mp){
            // The ampercent is so fucking important here
            sort(dests.begin(), dests.end(), greater<string>());
        }

        dfs("JFK", mp, result);
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(string src, unordered_map <string, vector<string>> &mp, vector <string> &result){
        while(mp[src].empty()!=1){
            string next = mp[src].back();
            mp[src].pop_back();

            dfs(next, mp, result);
        }
        result.push_back(src);
        return ;
    }
};
