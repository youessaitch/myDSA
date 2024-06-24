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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        map<int,vector<int>> mpp; //{{v},[]}
        queue<pair<TreeNode*,int>> q; //{root,{v}}
        q.push({root,0}); //{root,vertical}

        while(!q.empty()){
            int size = q.size();
            map<int, vector<int>> tmp;
            while(size--){
                auto node = q.front().first;
                auto v = q.front().second;
                q.pop();

                tmp[v].push_back(node->val);

                if(node->left) q.push({node->left,v-1});
                if(node->right) q.push({node->right,v+1});
            }

            for (auto& it : tmp) {
                sort(it.second.begin(), it.second.end()); // Sort nodes within each vertical level
                mpp[it.first].insert(mpp[it.first].end(), it.second.begin(), it.second.end());
            }
        }

        vector<vector<int>> ans;
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;

    }
};