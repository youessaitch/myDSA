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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            ListNode* p1 = lists[i];
            while(p1!=NULL){
                pq.push(p1->val);
                p1 = p1->next;
            }
        }
        ListNode* ans = new ListNode(-1);
        ListNode* p1 = ans;
        while(!pq.empty()){
            ListNode* node = new ListNode(pq.top());
            pq.pop();
            p1->next = node;
            p1 = p1->next;
        }
        return ans->next;
    }
};