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
    bool solve(ListNode* head, TreeNode* root) {
        if (!head) return true;  // Linked list fully traversed, path found.
        if (!root) return false; // Tree node is null, path does not exist.

        if (root->val != head->val) return false; // Values do not match.

        // Recursively check both left and right subtrees for the rest of the list.
        return solve(head->next, root->left) || solve(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false; // If the tree is empty, return false.

        // Check if the linked list starts at the current tree node.
        if (solve(head, root)) return true;

        // Otherwise, recursively check the left and right subtrees.
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
