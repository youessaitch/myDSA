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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v;
        ListNode* p1 = head;
        while(p1!=nullptr){
            v.push_back(p1->val);
            p1=p1->next;
        }
        reverse(v.begin()+left-1,v.begin()+right);
        p1=head;
        for(auto it: v){
            p1->val = it;
            p1=p1->next;
        }
        return head;
    }
};