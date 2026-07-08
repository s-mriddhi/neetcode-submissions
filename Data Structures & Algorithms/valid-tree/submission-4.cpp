class DSU {
    vector <int> parent, size;
    int comps;
public:
    DSU(int n){
        comps = n;
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i<n+1; i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(parent[node]!=node){
            parent[node] = findParent(parent[node]);
        }
        return parent[node];
    }

    bool unionBySize(int u, int v){
        int par_u = findParent(u);
        int par_v = findParent(v);
        if(par_u==par_v) return false;
        if(size[par_u]>size[par_v]){
            parent[par_v] = par_u;
            size[par_u]+=size[par_v];
        }
        else{
            parent[par_u] = par_v;
            size[par_v]+=size[par_u];
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
    bool validTree(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        if(e != n-1) return false;
        DSU d(n);
        for(auto edge : edges){
            if(!d.unionBySize(edge[0], edge[1])){
                return false;
            }
        }

        return d.components()==1;
    }
};
