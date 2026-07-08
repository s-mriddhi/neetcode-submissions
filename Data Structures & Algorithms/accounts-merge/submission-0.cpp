

class DSU {
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool union_rank(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return false;
        
        // Fix: Proper union-by-rank height updates
        if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu] += 1; // Only increment when depth ties
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU d(n);
        unordered_map<string, int> emailtoacc;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                const string& email = accounts[i][j];
                if(emailtoacc.count(email)) {
                    d.union_rank(i, emailtoacc[email]);
                } else {
                    emailtoacc[email] = i;
                }
            }
        }

        // Group mails by leader account
        unordered_map<int, vector<string>> emailGrp;
        for(const auto& [str, accID] : emailtoacc) {
            int leader = d.find(accID);
            emailGrp[leader].push_back(str);
        }

        // Build result
        vector<vector<string>> result;
        

        // Fix: Use the canonical leader ID for the name lookup
        for(auto& [leaderID, emails] : emailGrp) {
            vector<string> merged;
            
            // Look up the name belonging to the leader ID
            merged.push_back(accounts[leaderID][0]); 
            
            sort(emails.begin(), emails.end());
            
            for(auto& email : emails) {
                merged.push_back(email); // Optimize: Move strings instead of copying
            }

            result.push_back(merged);
        }

        return result;
    }
};
