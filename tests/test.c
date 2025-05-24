// tests/test.c
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../solutions/solution.c"  // Include the actual reverseList function


// Declare ListNode struct (must be consistent with solution.c)
struct ListNode {
    int val;
    struct ListNode *next;
};

// Declare the solution function from solution.c
bool isPalindrome(struct ListNode* head);

// Helper functions:
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* buildLinkedList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = createNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void freeLinkedList(struct ListNode* head) {
    while (head) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

bool test_case(int* arr, int size, bool expected) {
    struct ListNode* head = buildLinkedList(arr, size);
    bool result = isPalindrome(head);
    printf("Input: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\nOutput: %s\nExpected: %s\n", result ? "true" : "false", expected ? "true" : "false");
    if (result == expected) {
        printf("✅ Test Passed!\n");
        freeLinkedList(head);
        return true;
    } else {
        printf("❌ Test Failed!\n");
        freeLinkedList(head);
        return false;
    }
}

int main() {
    int passed = 0, failed = 0;

    struct {
        int arr[20];
        int size;
        bool expected;
    } tests[] = {
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
        {{1,2,3,2,2}, 5, false},
        {{9,9,9,9,9,9,9,9}, 8, true},
        {{1,2,3,2,1,0}, 6, false},
        {{0}, 1, true}
    };

    int n = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < n; i++) {
        if (test_case(tests[i].arr, tests[i].size, tests[i].expected)) passed++;
        else failed++;
        printf("---------------------------------------------\n");
    }

    printf("Summary:\n");
    printf("Total: %d\nPassed: %d\nFailed: %d\n", n, passed, failed);

    return 0;
}
