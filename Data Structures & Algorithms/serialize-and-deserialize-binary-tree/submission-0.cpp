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

class Codec {
private:
    void DFSserial(TreeNode* root, vector <string> &res){
        if(!root){
            res.push_back("N");
            return;
        }
        res.push_back(to_string(root->val));
        DFSserial(root->left, res);
        DFSserial(root->right, res);
        return;
    }
    string join(vector <string> res, string delim){
        ostringstream out;
        bool first = true;
        for(auto &str : res){
            if(!first){
                out<<delim;
            }
            out<<str;
            first = false;
        }
        return out.str();
    }

    TreeNode* DFSdeserial(vector <string> &res, int& i){
        if(res[i]=="N"){
            i++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(res[i]));
        i++;
        root->left = DFSdeserial(res, i);
        root->right = DFSdeserial(res, i);
        return root;
    }
    vector <string> split(string s, char delim){
        stringstream ss(s);
        vector<string> res;
        string item;
        while(getline(ss, item, delim)){
            res.push_back(item);
        }
        return res;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector <string> res;
        DFSserial(root, res);
        string output = join(res, ",");
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector <string> res = split(data, ',');
        int i =0;
        TreeNode* root = DFSdeserial(res, i);
        return root;
    }
};
