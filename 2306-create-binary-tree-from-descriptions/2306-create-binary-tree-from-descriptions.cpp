class Solution {
public:
    int n;
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mpp;
        n = descriptions.size();
        unordered_set<int> nonRoots;

        for(auto it: descriptions){
            int baap = it[0];
            int beta = it[1];
            bool left = it[2];
            nonRoots.insert(beta);

            if(mpp.find(baap)==mpp.end()){
                TreeNode* par = new TreeNode(baap);
                mpp[baap] = par;
            }

            if(mpp.find(beta)==mpp.end()){
                TreeNode* child = new TreeNode(beta);
                mpp[beta] = child;
            } 

            if(left) mpp[baap]->left = mpp[beta];
            else mpp[baap]->right = mpp[beta];
        }

        int sbkaBaap;
        for(auto it: descriptions){
            if(nonRoots.find(it[0])==nonRoots.end()){
                sbkaBaap = it[0];
                break;
            }
        }

        return mpp[sbkaBaap];
    }
};