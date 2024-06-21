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
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode* p1 = head;
        while(p1!=nullptr){
            v.push_back(p1->val);
            p1 = p1->next;
        }
        int ans = 0;
        int n = v.size();
        for(int i=0;i<n/2;i++){
            int sum = v[i] + v[n-1-i];
            ans = max(ans,sum);
        }
        return ans;
    }
};