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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        // vector<vector<int>> ans;
        queue<TreeNode*> q;
        int cnt = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            // vector<int> ds;
            while(size--){
                auto node = q.front();
                q.pop();
                // ds.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            cnt++;
        }
        return cnt;
    }
};