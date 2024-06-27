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
    void inorder(TreeNode* root, vector<int> &in) {
        if (!root) return;
        if (root->left) inorder(root->left, in);
        in.push_back(root->val);
        if (root->right) inorder(root->right, in);
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        
        vector<int> in;
        inorder(root, in);
        int n = in.size();
        int i=0,j=n-1;
        while(i<j){
            if(in[i]+in[j]==k) return true;
            else if(in[i]+in[j]<k) i++;
            else if(in[i]+in[j]>k) j--;
        }
        return false;
    }
};