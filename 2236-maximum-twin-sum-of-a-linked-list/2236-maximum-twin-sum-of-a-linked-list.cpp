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
    // Function to reverse a linked list
    // using the 3-pointer approach
    ListNode* reverseLinkedList(ListNode *head)
    {
        ListNode* temp = head;  
        ListNode* prev = NULL;  
        while(temp != NULL){  
            ListNode* front = temp->next;  
            temp->next = prev;  
            prev = temp;  
            temp = front; 
        }
        return prev;  
    }

    int pairSum(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return 0;
        }

        if(head->next->next==nullptr){
            return head->val + head->next->val;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // ListNode* f1 = slow->next;
        // slow->next = nullptr;

        ListNode* f2 = reverseLinkedList(slow);
        // slow->next = f2;

        int maxi = 0;
        ListNode* p1 = head;
        ListNode* p2 = f2;
        // slow=slow->next;
        while(p2!=nullptr){
            int sum = p2->val + p1->val;
            maxi = max(maxi,sum);
            p1 = p1->next;
            p2 = p2->next;
        }

        return maxi;
    }
};