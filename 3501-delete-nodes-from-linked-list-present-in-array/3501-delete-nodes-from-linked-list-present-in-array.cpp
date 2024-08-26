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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mpp;
        for(auto it: nums) mpp[it]++;

        ListNode* p1 = head;
        ListNode* t = new ListNode(-1);
        t->next = head;
        p1 = t->next;
        ListNode* prev = t;
        while(p1!=nullptr){
            int num = p1->val;
            if(mpp.find(num)!=mpp.end()){
                prev->next = p1->next;
                p1->next = nullptr;
                p1 = prev->next;
                continue;
            }
            p1 = p1->next;
            prev = prev->next;
        }

        return t->next;
    }
};