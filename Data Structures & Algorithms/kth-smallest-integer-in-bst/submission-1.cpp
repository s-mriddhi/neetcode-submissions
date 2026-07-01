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
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        dfs(root, k, ans);
        return ans;
    }

    void dfs(TreeNode* root, int& k, int &ans){
        if(!root) return;
        dfs(root->left, k, ans);
        if(k==0) return; // signifies that answer has already been found.
        k--;
        if(k==0) {ans = root->val; return;}
        dfs(root->right, k, ans);
    }
};
