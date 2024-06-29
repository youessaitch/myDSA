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
    #define ll unsigned long long
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        queue<pair<TreeNode*,ll>> q; //{root,index}
        q.push({root,0}); //index of root = 0

        ll maxWidth = 0;

        while(!q.empty()){
            ll L = q.front().second; //index of Left most node
            ll R = q.back().second; //index of Right most node
            maxWidth = max(maxWidth,R-L+1);

            ll size = q.size();
            while(size--){
                auto node = q.front().first;
                auto idx= q.front().second;
                q.pop();

                if(node->left) 
                    q.push({node->left,2*idx+1});
                if(node->right) 
                    q.push({node->right,2*idx+2});
            }
        }
        return maxWidth;
    }
};