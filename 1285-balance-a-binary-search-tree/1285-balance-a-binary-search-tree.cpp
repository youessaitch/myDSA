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
    void inorder(TreeNode* root, vector<int>&in){
        if(!root) return;

        if(root->left) inorder(root->left,in);
        in.push_back(root->val);
        if(root->right) inorder(root->right,in);
    }

    TreeNode* modify(int l, int r, vector<int>&in){
        if(l>r) return nullptr;

        int mid = l+(r-l)/2;

        TreeNode* node = new TreeNode(in[mid]);
        node->left = modify(l,mid-1,in);
        node->right = modify(mid+1,r,in);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return nullptr;
        vector<int> in;
        inorder(root,in);
        return modify(0,in.size()-1,in);
    }
};