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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p1 = head;
        ListNode* list = new ListNode(-1);
        ListNode* p2 = list;
        int sum= 0;
        p1 = p1->next;
        while(p1!=nullptr){
            if(p1->val != 0){
                sum += p1->val;
            }else{
                ListNode* temp = new ListNode(sum);
                p2->next = temp;
                p2 = p2->next;
                sum=0;
            }
            p1 = p1->next;
        }

        return list->next;
    }
};