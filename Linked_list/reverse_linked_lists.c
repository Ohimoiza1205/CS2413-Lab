#include <stdio.h>
#include <stdlib.h>

struct ListNode* reverseList(struct ListNode* head) {
    // Base case: If the list is empty or has only one node, return head as it is.
    if (!head || !head->next) return head;

    // Pointers for tracking previous and current nodes
    struct ListNode* previous = NULL;
    struct ListNode* current = head;
    struct ListNode* nextNode = NULL;

    // Traverse the list while updating the links
    while (current) {
        nextNode = current->next;  // Store the next node
        current->next = previous;  // Reverse the link direction
        previous = current;        // Move previous to current
        current = nextNode;        // Move current to next
    }
    
    // Return the new head of the reversed list (previous points to last node)
    return previous;
}
