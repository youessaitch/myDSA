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
    vector<int> solve(TreeNode* root, int distance, int &cnt){
        if(!root) return {0};
        if(!root->left && !root->right) return {1};

        vector<int> left = solve(root->left,distance,cnt);
        vector<int> right = solve(root->right,distance,cnt);

        for(auto x: left){
            for(auto y: right){
                if(x>0 && y>0){
                    if(x+y <= distance) cnt++;
                }
            }
        }

        vector<int> ans;
        for(auto x:left){
            if(x>0 && x<distance) ans.push_back(x+1);
        }

        for(auto x:right){
            if(x>0 && x<distance) ans.push_back(x+1);
        }

        return ans;
    }

    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;
        solve(root,distance,cnt);
        return cnt;
    }
};