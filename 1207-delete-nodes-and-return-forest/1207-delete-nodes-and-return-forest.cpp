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
    vector<TreeNode*> ans;

    TreeNode* solve(TreeNode* root, unordered_set<int> &st){
        if(!root) return NULL;

        root->left = solve(root->left,st);
        root->right = solve(root->right,st);

        if(st.find(root->val)!=st.end()){
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return NULL;
        }else return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        for(auto it: to_delete) st.insert(it);

        solve(root,st);

        if(st.find(root->val)==st.end()){
            ans.push_back(root);
        }

        return ans;

    }
};