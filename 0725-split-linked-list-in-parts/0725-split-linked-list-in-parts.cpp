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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,nullptr);
        int len = 0;

        ListNode* p1 = head;
        while(p1!=nullptr){
            len++;
            p1 = p1->next;
        }

        int part = len/k;
        int remain = len%k;

        p1 = head;
        ListNode* prev = nullptr;

        for(int i=0;p1 && i<k;i++){
            ans[i] = p1;

            for(int j=0;j<part;j++){
                prev = p1;
                p1 = p1->next;
            }

            if(remain>0){
                prev = p1;
                p1 = p1->next;
                remain--;
            }

            prev->next = nullptr;
        }

        return ans;
    }
};