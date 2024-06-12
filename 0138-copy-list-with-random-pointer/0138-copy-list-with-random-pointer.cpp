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

// What does the question asks?
// I was confused with the question for a bit. But understood it, Basically the question is to deep copy the linked list, that is make an exact copy.(replicate the random nodes too)
// If it was simple single linked list, it was simple. Just make a copy on the go and connect the nodes.
// But if the random element is present we have to replicate it to, just imagine you made a new node and the random of this node points to a node which is not yet created ?What will you do? How will you Point to that node, thats what we have to solve here,

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