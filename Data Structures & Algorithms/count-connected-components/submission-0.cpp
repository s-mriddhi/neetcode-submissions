class DSU{
    vector <int> parent, size;
    int comps;
    public:
        DSU(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i =0; i<=n; i++){
                parent[i] = i;
                size[i] = 1;
            }
            comps = n;
        }

        int findPar(int u){
            if(parent[u]!=u){
                parent[u] = findPar(parent[u]);
            }
            return parent[u];
        }

        bool unionSize(int u, int v){
            int p_u = findPar(u);
            int p_v = findPar(v);
            if(p_u == p_v) return false;
            if(size[p_u]>size[p_v]){
                parent[p_v] = p_u;
                size[p_u] += size[p_v];
            }
            else{
                swap(p_u, p_v);
                parent[p_v] = p_u;
                size[p_u] += size[p_v];
            }
            comps--;
            return true;
        }

        int components(){
            return comps;
        }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU d(n);
        for(auto edge : edges){
            d.unionSize(edge[0], edge[1]);
        }

        return d.components();
    }
};
