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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> v;
        ListNode* p1 = head;
        while(p1!=NULL){
            v.push_back(p1->val);
            p1 = p1->next;
        }
        int n = v.size();
        if(v.size()==0 || k==0) return head;
        int t = k%n;
        queue<int> q;
        for(int i=0;i<n-t;i++){
            q.push(v[i]);
        }
        int j=0;
        for(int i=n-t;i<n;i++){
            v[j]=v[i];
            j++;
        }
        while(!q.empty()){
            v[j] = q.front();
            q.pop();
            j++;
        }

        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        ListNode* ans = new ListNode(-1);
        ListNode* p2 = ans;
        for(int i=0;i<v.size();i++){
            ListNode* temp = new ListNode(v[i]);
            p2->next = temp;
            p2 = p2->next;
        }

        return ans->next;
    }
};