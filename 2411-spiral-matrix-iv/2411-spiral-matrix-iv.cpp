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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> v(n,vector<int>(m,-1));
        int l = 0,r = m-1,u = 0,d = n-1;
        // bool down = true;
        // bool right = true; 
        ListNode* p1 = head;
        while(p1!=nullptr && l<=r && u<=d){
                for(int i=l;i<=r;i++){
                    if(p1==nullptr) break;
                    v[u][i] = p1->val;
                    p1 = p1->next;
                }
                u++;
            
                for(int i=u;i<=d;i++){
                    if(p1==nullptr) break;
                    v[i][r] = p1->val;
                    p1 = p1->next;
                }
                r--;

                for(int i=r;i>=l;i--){
                    if(p1==nullptr) break;
                    v[d][i] = p1->val;
                    p1 = p1->next;
                }
                d--;

                for(int i=d;i>=u;i--){
                    if(p1==nullptr) break;
                    v[i][l] = p1->val;
                    p1 = p1->next;
                }
                l++;

        }

        return v;
    }
};