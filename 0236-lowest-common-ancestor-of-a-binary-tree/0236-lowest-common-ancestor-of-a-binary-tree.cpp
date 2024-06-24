/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, TreeNode* node, vector<TreeNode*> &path){
        if(!root) return;

        if(root == node){
            path.push_back(root);
            return;
        }

        path.push_back(root);
        dfs(root->left,node,path);
        dfs(root->right,node,path);
        if (path.back() != node) path.pop_back();

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        dfs(root,p,path1);
        dfs(root,q,path2);

        int ans = 0;
        TreeNode* res = nullptr;
        for(int i=0;i<min(path1.size(),path2.size());i++){
            if(path1[i]==path2[i]){ 
                res = path1[i];
            }
            else break;
        }

        return res;
    }
};