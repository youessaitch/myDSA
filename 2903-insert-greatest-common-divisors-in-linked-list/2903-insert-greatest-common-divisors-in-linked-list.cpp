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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int> v;
        ListNode* p1 = head;
        while(p1!=nullptr){
            v.push_back(p1->val);
            p1=p1->next;
        }
        ListNode* ans = new ListNode(-1);
        p1 = ans;
        for(int i=0;i<v.size()-1;i++){
            int t = __gcd(v[i],v[i+1]);
            ListNode* temp1 = new ListNode(v[i]);
            p1->next = temp1;
            p1 = p1->next;
            ListNode* temp2 = new ListNode(t);
            p1->next = temp2;
            p1 = p1->next;
        }
        ListNode* last = new ListNode(v[v.size()-1]);
        p1->next = last;
        return ans->next;
    }
};