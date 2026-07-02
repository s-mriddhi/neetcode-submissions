/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    private:
        string serialize(TreeNode* root){
            vector <string> res;
            dfs(root, res);
            return join(res, ",");
        }
        void dfs(TreeNode* root,  vector <string> &res){
            if(!root){
                res.push_back("N");
                return;
            }
            res.push_back(to_string(root->val));
            dfs(root->left , res);
            dfs(root->right, res);
            return;
        }
        string join(vector <string> res, string delim){
            ostringstream out;
            bool first = true;
            for(auto str : res){
                if(!first){
                    out<<delim;
                }
                out<<str;
                first = false;
            }
            return out.str();
        }

    vector <int> getZ(string s){
        
        int n = s.size();
        vector <int> z(n,0);
        int l=0;
        int r=0;
        for(int i =1; i<n;i++)
        {
            if(i<=r){
                z[i] = min(r-i+1, z[i-l]);
            }
            while(i+z[i]<n && s[z[i]]==s[i + z[i]]){
                z[i]++;
            }
            if(i + z[i]-1>r){
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s_root = serialize(root);
        string s_subroot = serialize(subRoot);
        string combined = s_subroot + "@" + s_root;
        vector <int> z = getZ(combined);
        for(int i=s_subroot.size()+1;i<combined.size();i++){
            if(z[i]==s_subroot.size()) return true;
        }
        return false;
    }
};
