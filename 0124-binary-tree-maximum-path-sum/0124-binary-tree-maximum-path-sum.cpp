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
    int maxi = -1e9;
    int solve(TreeNode* root){
        if(!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int res = 0;
        if(left>0) res += left;
        if(right>0) res += right;
        res += root->val;
 
        if(res>maxi) maxi = res;

        if(left <0 && right < 0) return root->val;
        return root->val + max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};