// test.cpp
#include <iostream>
#include <vector>
#include <string>
#include "../solutions/solution.cpp"   // include the solution file here

using namespace std;

// Helper: Convert vector<int> to linked list
ListNode* vectorToList(const vector<int>& nums) {
    ListNode dummy;
    ListNode* current = &dummy;
    for (int val : nums) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy.next;
}

// Helper: Print vector<int>
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

// Test runner for linked list palindrome
bool runTestLinkedList(const vector<int>& input, bool expected, const string& description) {
    Solution sol;
    ListNode* head = vectorToList(input);

    cout << "Test: " << description << endl;
    cout << "Input: ";
    printVector(input);
    cout << endl;

    bool result = sol.isPalindrome(head);

    cout << "Output: " << (result ? "true" : "false") << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;

    bool passed = (result == expected);
    if (passed) {
        cout << "Result: PASSED ✅" << endl;
    } else {
        cout << "Result: FAILED ❌" << endl;
    }
    cout << "--------------------------" << endl;

    // Cleanup linked list
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return passed;
}

int main() {
    cout << "Running Palindrome Test Cases (Linked List)...\n\n";

    int passedCount = 0;
    int failedCount = 0;

    // Run tests and count passed/failed
    if (runTestLinkedList({1, 2, 2, 1}, true, "Even-length palindrome")) passedCount++; else failedCount++;
    if (runTestLinkedList({1, 2}, false, "Not a palindrome")) passedCount++; else failedCount++;
    if (runTestLinkedList({1}, true, "Single element")) passedCount++; else failedCount++;
    if (runTestLinkedList({}, true, "Empty list")) passedCount++; else failedCount++;
    if (runTestLinkedList({1, 2, 3, 2, 1}, true, "Odd-length palindrome")) passedCount++; else failedCount++;
    if (runTestLinkedList({1, 2, 3, 3, 2, 1}, true, "Even-length symmetric")) passedCount++; else failedCount++;
    if (runTestLinkedList({1, 2, 3, 4, 2, 1}, false, "Near-palindrome")) passedCount++; else failedCount++;
    if (runTestLinkedList({1, 1, 1, 1, 1}, true, "All elements same")) passedCount++; else failedCount++;
    if (runTestLinkedList({1, 2, 3, 4, 3, 2, 1}, true, "Symmetric complex")) passedCount++; else failedCount++;
    if (runTestLinkedList({1, 2, 3, 4, 5, 2, 1}, false, "Non-palindrome pattern")) passedCount++; else failedCount++;
    if (runTestLinkedList({1, 0, 1}, true, "Palindrome with zero")) passedCount++; else failedCount++;
    if (runTestLinkedList({1, 0, 0, 1}, true, "Even-length with zeros")) passedCount++; else failedCount++;
    if (runTestLinkedList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, false, "Sequential numbers")) passedCount++; else failedCount++;
    if (runTestLinkedList({1, 2, 3, 4, 3, 2, 2}, false, "Last mismatch")) passedCount++; else failedCount++;
    if (runTestLinkedList({9, 9, 9, 9, 9, 9, 9, 9}, true, "All 9s")) passedCount++; else failedCount++;
    if (runTestLinkedList({1, 2, 3, 2, 1, 0}, false, "Correct prefix but fails at end")) passedCount++; else failedCount++;
    if (runTestLinkedList({0}, true, "Single zero")) passedCount++; else failedCount++;

    cout << "\n✅ All test cases finished!" << endl;
    cout << "Passed: " << passedCount << endl;
    cout << "Failed: " << failedCount << endl;

    return 0;
}
