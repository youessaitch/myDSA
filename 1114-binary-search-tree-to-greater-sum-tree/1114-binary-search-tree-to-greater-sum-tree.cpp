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

    // void inorder(TreeNode* root,vector<int> &v){
    //     if(!root) return;

    //     if(root->left) inorder(root->left,v);
    //     v.push_back(root->val);
    //     if(root->right) inorder(root->right,v);
    // }

    // void reconstruct(TreeNode* root, vector<int>&v, int &idx){
    //     if(!root) return;

    //     if(root->left) reconstruct(root->left,v,idx);
    //     root->val = v[idx];
    //     idx++;
    //     if(root->right) reconstruct(root->right,v,idx);
    // }

    //R->node->L
    void dfs(TreeNode* root,int &sum){
        if(!root) return;

        dfs(root->right,sum); //all the way to the last node in right
        sum+=root->val;
        root->val = sum;

        dfs(root->left,sum);

    }

    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return nullptr;
        int sum = 0;
        dfs(root,sum);
        return root;
    }
};