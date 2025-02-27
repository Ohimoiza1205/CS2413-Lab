#include <stdio.h>
#include <stdlib.h>

struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a temporary dummy node (stack allocated)
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *curr = &dummy; // Start from dummy node

    while (curr->next != NULL) {
        if (curr->next->val == val) {
            struct ListNode *toDelete = curr->next; // Save reference to the node being removed
            curr->next = curr->next->next; // Skip the node
            free(toDelete); // Free memory
        } else {
            curr = curr->next; // Move to the next node
        }
    }

    return dummy.next; // Return the new head
}
