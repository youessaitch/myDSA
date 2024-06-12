/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p1 = head;
        unordered_map<Node*,Node*> mpp;
        while(p1!=NULL){
            mpp[p1] = new Node(p1->val);
            p1 = p1->next;
        }
        
        p1 = head;
        while(p1!=NULL){
            mpp[p1]->next = mpp[p1->next];
            mpp[p1]->random = mpp[p1->random];
            p1 = p1->next;
        }

        return mpp[head];
    }
};