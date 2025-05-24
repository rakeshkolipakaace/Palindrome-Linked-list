// solution.c
#include <stdbool.h>
#include <stdlib.h>

// Definition for singly-linked list....
struct ListNode {
    int val;
    struct ListNode *next;
};

// Reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Check if list is palindrome
bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast) slow = slow->next;

    struct ListNode* secondHalf = reverseList(slow);
    struct ListNode* firstHalf = head;
    struct ListNode* copy = secondHalf;

    bool palindrome = true;
    while (secondHalf) {
        if (firstHalf->val != secondHalf->val) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    reverseList(copy);
    return palindrome;
}
