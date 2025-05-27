#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head) {
   
       // write your code here....
          // Reverse the first half while finding middle using slow/fast pointers

    struct ListNode *slow = head, *fast = head;
    struct ListNode *prev = NULL, *next = NULL;
    
    // Reverse first half while moving slow pointer forward
    while (fast && fast->next) {
        fast = fast->next->next;
        
        // Reverse the node that slow points to
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    
    // If list length is odd, skip the middle node
    if (fast) {
        slow = slow->next;
    }
    
    // Now compare reversed first half (pointed by prev) with second half (slow)
    while (prev && slow) {
        if (prev->val != slow->val) {
            return false;
        }
        prev = prev->next;
        slow = slow->next;
    }
    
    return true;
}
