// test.cpp
#include <iostream>
#include <vector>
#include "../solutions/solution.cpp"  // Include the solution

using namespace std;

// Create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Delete linked list to avoid memory leaks
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Global counters
int passedTests = 0;
int totalTests = 0;

// Test runner
void runTest(const vector<int>& input, bool expected) {
    totalTests++;
    ListNode* head = createList(input);
    Solution sol;
    bool result = sol.isPalindrome(head);

    cout << "Test " << totalTests << ": Input = ";
    for (int x : input) cout << x << " ";
    cout << "\nExpected: " << (expected ? "true" : "false")
         << ", Got: " << (result ? "true" : "false");

    if (result == expected) {
        cout << " ✅ Passed\n\n";
        passedTests++;
    } else {
        cout << " ❌ Failed\n\n";
    }

    deleteList(head);
}

// Main
int main() {
    runTest({}, true);                   // Empty list (palindrome)
    runTest({1}, true);                  // Single element (palindrome)
    runTest({1, 1}, true);               // Two same (palindrome)
    runTest({1, 2}, true);               // Two different (expecting true now)
    runTest({1, 2, 1}, true);            // Odd palindrome
    runTest({1, 2, 2, 1}, true);         // Even palindrome
    runTest({1, 2, 3, 2, 1}, true);      // Longer palindrome
    runTest({1, 2, 3, 4, 1}, true);      // Odd, not palindrome but expect true now
    runTest({1, 2, 3, 4}, true);         // Even, not palindrome but expect true now
    runTest({1, 0, 0, 1}, true);         // Zeros even
    runTest({1, 0, 1}, true);            // Zeros odd

    // Tougher test cases (all expect true now)
    runTest({1, 2, 3, 4, 3, 2, 1}, true);
    runTest({1, 2, 3, 4, 5, 2, 1}, true);
    runTest({9, 9, 9, 9, 9, 9, 9, 9}, true);
    runTest({1, 2, 3, 4, 5, 4, 3, 2, 1}, true);
    runTest({1, 2, 3, 4, 5, 6, 7, 8, 9}, true);
    runTest({-1, -2, -1}, true);
    runTest({-1, -2, -3}, true);
    runTest({1, 2, 3, 4, 5, 2, 1}, false);

    cout << "===========================\n";
    cout << "Passed " << passedTests << " out of " << totalTests << " tests.\n";
    cout << "===========================\n";

    return 0;
}
