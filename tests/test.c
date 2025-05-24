// test.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declare ListNode and isPalindrome (defined in solution.c)
struct ListNode {
    int val;
    struct ListNode* next;
};

bool isPalindrome(struct ListNode* head);

// Build a linked list from an array
struct ListNode* build_linked_list(int* arr, int size) {
    if (size == 0) return NULL;

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

// Free a linked list
void free_list(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Run one test case
bool test_case(int* arr, int size, bool expected) {
    struct ListNode* head = build_linked_list(arr, size);
    bool result = isPalindrome(head);

    printf("Input: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");

    printf("Output: %s\n", result ? "true" : "false");
    printf("Expected: %s\n", expected ? "true" : "false");

    bool passed = (result == expected);
    printf("%s Test %s!\n", passed ? "✅" : "❌", passed ? "Passed" : "Failed");

    free_list(head);
    return passed;
}

int main() {
    struct {
        int arr[20];
        int size;
        bool expected;
    } test_cases[] = {
        {{1,2,2,1}, 4, true},
        {{1,2}, 2, false},
        {{1}, 1, true},
        {{}, 0, true},
        {{1,2,3,2,1}, 5, true},
        {{1,2,3,3,2,1}, 6, true},
        {{1,2,3,4,2,1}, 6, false},
        {{1,1,1,1,1}, 5, true},
        {{1,2,3,4,3,2,1}, 7, true},
        {{1,2,3,4,5,2,1}, 7, false},
        {{1,0,1}, 3, true},
        {{1,0,0,1}, 4, true},
        {{1,2,3,4,5,6,7,8,9,10}, 10, false},
        {{1,2,3,4,3,2,2}, 7, false},
        {{9,9,9,9,9,9,9,9}, 8, true},
        {{1,2,3,2,1,0}, 6, false},
        {{0}, 1, true},
    };

    int passed = 0;
    int failed = 0;
    int total = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < total; i++) {
        printf("Test Case %d:\n", i + 1);
        bool ok = test_case(test_cases[i].arr, test_cases[i].size, test_cases[i].expected);
        if (ok) passed++;
        else failed++;
        printf("----------------------------------------\n");
    }

    printf("\nSummary:\n");
    printf("Total Test Cases: %d\n", total);
    printf("Passed: %d\n", passed);
    printf("Failed: %d\n", failed);

    return 0;
}
