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
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        int maxSum=INT_MIN;
        int cnt = 0;

        while(!q.empty()){
            int nodelvlsum=0;
            cnt++;
            int size = q.size();
            while(size--){
                auto node = q.front();
                q.pop();

                nodelvlsum+=(node->val);

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }
            if(nodelvlsum>maxSum){
                ans = cnt;
                maxSum = nodelvlsum;
            }
        }
        return ans;
    }
};