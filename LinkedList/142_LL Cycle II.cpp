class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        if (!isCycle) {
            return NULL;
        }

        slow = head;
        ListNode* prev = NULL;   // Used to remove the cycle

        while (slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL;   // Remove cycle (as in your notes)

        return slow;
    }
};
