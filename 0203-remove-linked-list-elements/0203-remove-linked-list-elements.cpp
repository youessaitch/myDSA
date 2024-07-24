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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        // ListNode* p1 = head;
        ListNode* node = new ListNode(-1);
        node->next = head;
        ListNode* curr = head;
        ListNode* prev = node;
        while(curr!=nullptr){
            if(curr->val == val){
                if(curr->next != nullptr)
                    prev->next = curr->next;
                else prev->next = nullptr;

                curr = curr->next;
                continue;
            }
            curr = curr->next;
            prev = prev->next;
        }
        return node->next;
    }
};