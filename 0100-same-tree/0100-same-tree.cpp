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
    // void dfs(TreeNode* node, vector<int> &a){
    //     if(!node) return;

        
    // }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !p) return false;

        queue<TreeNode*> qu;
        qu.push(p);
        qu.push(q);

        while(!qu.empty()){
            auto p1 = qu.front();
            qu.pop();
            auto q1 = qu.front();
            qu.pop();

            if(!p1 && !q1)continue;
            if(!p1 || !q1) return false;
            if(p1->val != q1->val) return false;

            qu.push(p1->left);
            qu.push(q1->left);
            qu.push(p1->right);
            qu.push(q1->right);
        }
        return true;
    }
};