class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> mpp; // Map to store the node and its index
        ListNode* p1 = head;
        int idx = 0;

        while (p1 != nullptr) {
            if (mpp.find(p1) != mpp.end()) {
                return p1; // Cycle detected, return the start of the cycle
            }
            mpp[p1] = idx; // Store the node and its index in the map
            p1 = p1->next;
            idx++;
        }
        
        return nullptr; // No cycle detected
    }
};
