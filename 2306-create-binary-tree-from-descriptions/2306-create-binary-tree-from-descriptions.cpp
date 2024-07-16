class Solution {
public:
    int n;
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mpp; //store the nodes (check if we have made the node already else create a new node)
        n = descriptions.size();
        unordered_set<int> nonRoots; // the node which was never a child will be the root node

        for(auto it: descriptions){
            int baap = it[0];
            int beta = it[1];
            bool left = it[2];
            nonRoots.insert(beta); //insert all childs in the set

            if(mpp.find(baap)==mpp.end()){ //if node not made already then create
                TreeNode* par = new TreeNode(baap);
                mpp[baap] = par;
            }

            if(mpp.find(beta)==mpp.end()){ //if node not made already then create
                TreeNode* child = new TreeNode(beta);
                mpp[beta] = child;
            } 

            if(left) mpp[baap]->left = mpp[beta]; // do the stuffs in map
            else mpp[baap]->right = mpp[beta];
        }

        int sbkaBaap; // the node which was never a child will be the root node
        for(auto it: descriptions){
            if(nonRoots.find(it[0])==nonRoots.end()){
                sbkaBaap = it[0];
                break;
            }
        }

        return mpp[sbkaBaap];
    }
};