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
    TreeNode* LCA(TreeNode* root, int x, int y){
        if(!root) return NULL;

        if(root->val == x || root->val == y) return root;

        auto leftN = LCA(root->left,x,y); //go left
        auto rightN = LCA(root->right,x,y); //go right

        if(leftN && rightN) return root; //if got some value from left and right then that root will be the LCA
 
        if(leftN) return leftN; //if (left!= null && right ==null) lca = left;

        return rightN;
    }

    bool dfs(TreeNode* ancestor, int x, string &t) {
        if (!ancestor) return false;
        if (ancestor->val == x) return true;

        // Explore left
        t.push_back('L');
        if (dfs(ancestor->left, x, t)) return true;
        t.pop_back(); // backtrack

        // Explore right
        t.push_back('R');
        if (dfs(ancestor->right, x, t)) return true;
        t.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        // s->t
        //5 1 3
        //5 2 6
        string ans = "";
        TreeNode* ancestor = LCA(root,startValue,destValue);
        string LCAtoSrc = "";
        string LCAtoDes = "";

        dfs(ancestor,startValue,LCAtoSrc);
        dfs(ancestor,destValue,LCAtoDes);

        //append 'U' for LCAtoSrc 
        for(int i=0;i<LCAtoSrc.size();i++) ans+='U';
        ans+=LCAtoDes;

        return ans;
    }
};