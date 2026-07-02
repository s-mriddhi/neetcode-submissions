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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
    int solve(TreeNode* root, int &res){
        if(!root) return 0;
        int l = root->val + solve(root->left, res);
        int r = root->val + solve(root->right, res);
        int cur_max = max(max(l,r),max(l+r-root->val, root->val));
        res = max(res,cur_max);
        return max(max(l,r), root->val);
    }
};
