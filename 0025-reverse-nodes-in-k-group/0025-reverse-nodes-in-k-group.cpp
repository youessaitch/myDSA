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
//TC = O(N)
//SC = O(k) stack can hold max k (assuming)
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<int> st;
        ListNode* p1 = head;
        ListNode* ans = new ListNode(-1);
        ListNode* p2 = ans;
        int t = k;
        while(p1!=NULL){
            while(t!=0 && p1!=NULL){
                st.push(p1->val);
                p1=p1->next;
                t--;
            }
            t=k;
            if(st.size()==k){
                while(!st.empty()){
                    ListNode* temp = new ListNode(st.top());
                    st.pop();
                    p2->next = temp;
                    p2 = p2->next;
                }
            }else if(st.size()<k){
                vector<int> t;
                while(!st.empty()){
                    t.push_back(st.top());
                    st.pop();
                }
                for(int i=t.size()-1;i>=0;i--){
                    ListNode* temp = new ListNode(t[i]);
                    p2->next = temp;
                    p2 = p2->next;
                }
            }
        }
        return ans->next;
    }
};