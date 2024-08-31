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
    vector<int> pre;

    void preorder(TreeNode* root){
        if(!root) return;

        pre.push_back(root->val);
        if(root->left) preorder(root->left);
        if(root->right) preorder(root->right);
    }

    void flatten(TreeNode* root) {
        if(!root) return;

        preorder(root);

        TreeNode* p1 = root;

        for(int i=1;i<pre.size();i++){
            TreeNode* temp = new TreeNode(pre[i]);
            p1->right = temp;
            p1->left = nullptr;
            p1 = p1->right;
        }
    }
};