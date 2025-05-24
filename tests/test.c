#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../solutions/solution.c"  // solution.c contains struct ListNode and isPalindrome()

// Create linked list from array
struct ListNode* createList(int* arr, int size) {
    if (size == 0 || arr == NULL) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;

    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        current->next = node;
        current = node;
    }
    return head;
}

// Free list memory
void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Run a single test
void runTest(int* arr, int size, const char* desc, bool expected) {
    printf("Test: %s\n", desc);
    struct ListNode* head = createList(arr, size);
    bool result = isPalindrome(head);
    printf("Expected: %s\n", expected ? "true" : "false");
    printf("Actual:   %s\n", result ? "true" : "false");
    printf("Result: %s ✅\n\n", (result == expected) ? "PASSED" : "FAILED");
    freeList(head);
}

int main() {
    // Basic tests
    int arr1[] = {1, 2, 2, 1};
    runTest(arr1, 4, "Even Palindrome", true);

    int arr2[] = {1, 2};
    runTest(arr2, 2, "Not Palindrome", false);

    int arr3[] = {1};
    runTest(arr3, 1, "Single Node", true);

    int arr4[] = {};
    runTest(arr4, 0, "Empty List", true);

    int arr5[] = {1, 2, 3, 2, 1};
    runTest(arr5, 5, "Odd Palindrome", true);

    int arr6[] = {1, 2, 3, 3, 2, 1};
    runTest(arr6, 6, "Even Palindrome Symmetric", true);

    int arr7[] = {1, 2, 3, 4, 2, 1};
    runTest(arr7, 6, "Non-Palindrome", false);

    // Additional test cases
    int arr8[] = {1, 1, 1, 1, 1};
    runTest(arr8, 5, "All Same Elements", true);

    int arr9[] = {1, 2, 3, 4, 3, 2, 1};
    runTest(arr9, 7, "Odd Length Palindrome", true);

    int arr10[] = {1, 2, 3, 4, 5, 2, 1};
    runTest(arr10, 7, "Odd Length Non-Palindrome", false);

    int arr11[] = {1, 0, 1};
    runTest(arr11, 3, "Palindrome With Zero", true);

    int arr12[] = {1, 0, 0, 1};
    runTest(arr12, 4, "Even Length Palindrome With Zeros", true);

    int arr13[] = {1,2,3,4,5,6,7,8,9,10};
    runTest(arr13, 10, "Strictly Increasing", false);

    int arr14[] = {1,2,3,4,3,2,2};
    runTest(arr14, 7, "Almost Palindrome (Fails at End)", false);

    int arr15[] = {9,9,9,9,9,9,9,9};
    runTest(arr15, 8, "Even Length All Same Digits", true);

    int arr16[] = {1,2,3,2,1,0};
    runTest(arr16, 6, "Palindrome + Extra Element at End", false);

    int arr17[] = {0};
    runTest(arr17, 1, "Single Zero", true);

    printf("All tests done.\n");
    return 0;
}
