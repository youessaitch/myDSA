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
    void preorder(TreeNode* root, vector<int> &pre){
        if(!root) return;

        pre.push_back(root->val);
        if(root->left)
            preorder(root->left,pre);
        if(root->right)
            preorder(root->right,pre);
    }

    void flatten(TreeNode* root) {
        if (!root) return;

        vector<int> pre;
        preorder(root,pre);

        for(int i=0;i<pre.size();i++){
            cout<<pre[i]<<" ";
        }

        TreeNode* curr = root;
        //i=0 is the root itself in preorder, so start with i=1
        for(int i=1;i<pre.size();i++){
            TreeNode* node = new TreeNode(pre[i]);

            curr->left = nullptr;
            curr->right = node;
            curr = curr->right;
        }

    }
};