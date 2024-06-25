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
    ListNode* swapPairs(ListNode* head) {
        vector<int> nodes;
        ListNode* p1 = head;
        while(p1!=nullptr){
            nodes.push_back(p1->val);
            p1=p1->next;
        }
        for(int i=0;i<nodes.size();i+=2){
            if(i+1<nodes.size()){
                swap(nodes[i],nodes[i+1]);
            }
        }
        ListNode* list = new ListNode(-1);
        p1 = list;
        for(int i=0;i<nodes.size();i++){
            ListNode* temp = new ListNode(nodes[i]);
            p1->next = temp;
            p1=p1->next;
        }
        return list->next;
    }
};