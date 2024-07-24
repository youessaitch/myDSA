/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        unordered_map<ListNode*,int> mpp;
        while(p1!=nullptr){
            mpp[p1]++;
            p1=p1->next;
        }
        while(p2!=nullptr){
            if(mpp.find(p2)!=mpp.end()) return p2;
            p2=p2->next;
        }
        return nullptr;

    }
};