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
    bool solve(TreeNode* a, TreeNode* b){
        if(a == nullptr && b == nullptr) return true;
        if(a == nullptr || b == nullptr) return false;

        // if(a->left == a->right) return true;

        if(a->val != b->val) return false;
        // if(a->val == b->val) return true;

        return solve(a->left,b->left) && solve(a->right,b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;

        if(!root) return false;

        if(solve(root,subRoot)) return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};