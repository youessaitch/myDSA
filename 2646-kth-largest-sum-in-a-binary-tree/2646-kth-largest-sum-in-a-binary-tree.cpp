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
#define ll long long

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        queue<TreeNode*> q;
        q.push(root);

        multimap<ll,ll,greater<ll>> mpp;

        while(!q.empty()){
            int size = q.size();
            ll sum = 0;
            while(size--){
                auto top = q.front();
                q.pop();

                sum += (ll)top->val;

                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            mpp.insert({sum,1});
        }
        
        if(mpp.size()<k) return -1;

        auto it = mpp.begin();
        for(auto i = 1;i<k;i++){
            ++it;
        }
        
        return it->first;
    }
};