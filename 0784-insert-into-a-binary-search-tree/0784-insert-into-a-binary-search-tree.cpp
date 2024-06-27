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
    // void inorder(TreeNode* root, vector<int> &in){
    //     if(!root) return;

    //     if(root->left) inorder(root->left,in);
    //     in.push_back(root->val);
    //     if(root->right) inorder(root->right,in);
    // }

    // TreeNode* modify(int l, int r, vector<int>& in) {
    //     if (l > r) return nullptr;
        
    //     int mid = l + (r - l) / 2;
        
    //     TreeNode* node = new TreeNode(in[mid]);
    //     node->left = modify(l, mid - 1, in);
    //     node->right = modify(mid + 1, r, in);
    //     return node;
    // }

    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     if(!root) new TreeNode(val);
    //     vector<int> in;
    //     inorder(root,in);
    //     in.push_back(val);
    //     sort(in.begin(),in.end());
    //     return modify(0,in.size()-1,in);
    // }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* p1 = root; //pointer like in linked list
        while(p1){
            if(p1->val > val){
                if(p1->left) p1 = p1->left;
                else{
                    p1->left = new TreeNode(val);
                    break;
                }
            }else{
                if(p1->right) p1 = p1->right;
                else{
                    p1->right = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};