// Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

// Example 1:


// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
 

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n+1 steps ahead
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both until fast reaches end
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node from end
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy->next;
    }
};