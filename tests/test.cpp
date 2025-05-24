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
void runTest(const vector<int>& input, bool expected, const string& testName = "") {
    totalTests++;
    ListNode* head = createList(input);
    Solution sol;
    bool result = sol.isPalindrome(head);

    cout << "Test " << totalTests << " " << (testName.empty() ? "" : ("- " + testName)) << ": Input = ";
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
    // From your original tests
    runTest({}, true, "Empty list");
    runTest({1}, true, "Single node");
    runTest({2, 2}, true, "Two equal nodes");
    runTest({1, 1, 1}, true, "All same odd");
    runTest({1, 2, 1}, true, "Odd-length palindrome");
    runTest({1, 2, 2, 1}, true, "Even-length palindrome");
    runTest({3, 4, 5, 4, 3}, true, "Complex odd palindrome");
    runTest({9, 8, 8, 9}, true, "Complex even palindrome");
    runTest({7, 7, 7, 7}, true, "All same values");
    runTest({1, 2, 3}, false, "Only failing non-palindrome");
    runTest({1, 2, 1}, true, "Recheck correct palindrome");
    runTest({1, 2, 3, 2, 1}, true, "Larger palindrome");

    // Your previous tests from existing main (adjusted expectations)
    runTest({1, 1}, true, "Two same");
    runTest({1, 2}, false, "Two different - not palindrome");
    runTest({1, 2, 3, 4, 1}, false, "Odd, not palindrome");
    runTest({1, 2, 3, 4}, false, "Even, not palindrome");
    runTest({1, 0, 0, 1}, true, "Zeros even");
    runTest({1, 0, 1}, true, "Zeros odd");
    runTest({1, 2, 3, 4, 3, 2, 1}, true, "Long palindrome");
    runTest({1, 2, 3, 4, 5, 2, 1}, false, "Not palindrome");
    runTest({9, 9, 9, 9, 9, 9, 9, 9}, true, "All same values long");
    runTest({1, 2, 3, 4, 5, 4, 3, 2, 1}, true, "Long palindrome 2");
    runTest({1, 2, 3, 4, 5, 6, 7, 8, 9}, false, "Long non-palindrome");
    runTest({-1, -2, -1}, true, "Negative values palindrome");
    runTest({-1, -2, -3}, false, "Negative values non-palindrome");

    cout << "===========================\n";
    cout << "Passed " << passedTests << " out of " << totalTests << " tests.\n";
    cout << "===========================\n";

    return 0;
}
