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
    void dfs(TreeNode* root, int targetSum, int sum, bool &ans){
        if(!root) return;

        sum += root->val;

        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum){
                ans = true;
                return;
            }
        }

        if(root->left) dfs(root->left, targetSum, sum, ans);
        if(root->right) dfs(root->right, targetSum, sum, ans);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = false;
        dfs(root, targetSum, sum, ans);
        return ans;
    }
};