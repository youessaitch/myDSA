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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        ListNode* p1 = head;
        while(p1!=nullptr){
            v.push_back(p1->val); //store the values in a vector
            p1 = p1->next;
        }
        int n = v.size();
        if(n<=3) return {-1,-1}; //if n<=3, there cant be two critical points

        vector<int> critical;
        for(int i=1;i<n-1;i++){ //push the indices of all the critical points
            if((v[i]>v[i-1] && v[i]>v[i+1]) || (v[i]<v[i-1] && v[i]<v[i+1])){
                critical.push_back(i);
            }
        }
        if(critical.size()<2) return {-1,-1}; //there cant be two critical points
        int maxi = -1e5;
        int mini = 1e5;
        sort(critical.begin(),critical.end());
        maxi = critical[critical.size()-1] - critical[0]; //maximum diff
        for(int i=1;i<critical.size();i++){
            mini = min(mini,critical[i]-critical[i-1]); //finding minimum
        }
        return {mini,maxi};
    }
};