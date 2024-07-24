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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* curr = head->next;
        ListNode* prev = head;
        while(curr!=nullptr){
            if(curr->val == prev->val){
                if(curr->next != nullptr){
                    prev->next = curr->next;
                }
                else prev->next = nullptr;

                curr = curr->next;
                continue;
            }
            curr=curr->next;
            prev=prev->next;
        }
        return head;
    }
};