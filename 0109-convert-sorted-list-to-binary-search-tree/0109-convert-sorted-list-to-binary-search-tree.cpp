/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* modify(int l, int r, vector<int>& in) {
        if (l > r) return nullptr;
        
        int mid = l + (r - l) / 2;
        
        TreeNode* node = new TreeNode(in[mid]);
        node->left = modify(l, mid - 1, in);
        node->right = modify(mid + 1, r, in);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> in;
        ListNode* p1 = head;
        while(p1!=nullptr){
            in.push_back(p1->val);
            p1 = p1->next;
        }

        return modify(0,in.size()-1,in);
    }
};