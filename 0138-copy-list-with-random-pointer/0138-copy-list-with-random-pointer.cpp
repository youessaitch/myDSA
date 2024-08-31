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
        Node* ans = new Node(-1);
        Node* p2 = ans;
        unordered_map<Node*,Node*> mpp;

        while(p1!=nullptr){
            Node* temp = new Node(p1->val);
            mpp[p1] = temp; //original to new mapping
            p2->next = temp;
            p1=p1->next;
            p2=p2->next;
        }

        p2->next = nullptr;

        p2 = ans->next;
        p1 = head;
        while(p1!=nullptr){
            p2->random = mpp[p1->random];
            p1=p1->next;
            p2=p2->next;
        }

        return ans->next;
    }
};