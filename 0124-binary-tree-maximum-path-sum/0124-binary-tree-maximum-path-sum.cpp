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
    int dfs(TreeNode* root, int &res){
        if(!root) return 0;

        int lh = max(0,dfs(root->left,res));
        int rh = max(0,dfs(root->right,res));
        
        res = max(res,lh + rh + root->val);

        return max(lh,rh) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int res = -1e5;
        dfs(root,res);
        return res;
    }
};