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
    ListNode* sortList(ListNode* head) {
        priority_queue<int,vector<int>,greater<int>> pq;
        ListNode* p1 = head;
        while(p1!=nullptr){
            pq.push(p1->val);
            p1 = p1->next;
        }
        p1 = head;
        while(!pq.empty()){
            // ListNode* node = new ListNode(pq.top());
            p1->val = pq.top();
            pq.pop();
            p1 = p1->next;
        }
        return head;
    }
};