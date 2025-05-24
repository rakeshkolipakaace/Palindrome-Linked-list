#include <iostream>
#include <vector>
#include "../solutions/solution.cpp" // Make sure this path points to your solution file

using namespace std;

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& vals) {
    ListNode dummy;
    ListNode* current = &dummy;
    for (int val : vals) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy.next;
}

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]";
}

// Helper function to test one case
bool test(const vector<int>& input, bool expected) {
    Solution solution;
    ListNode* head = createLinkedList(input);
    bool result = solution.isPalindrome(head);

    cout << "Input: ";
    printVector(input);
    cout << "\nOutput: " << (result ? "true" : "false") << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;

    bool passed = (result == expected);
    cout << (passed ? "✅ Test Passed!" : "❌ Test Failed!") << endl;
    cout << "---------------------------------------------" << endl;
    return passed;
}

// Main test runner
int main() {
    bool all_passed = true;

    all_passed &= test({1, 2, 2, 1}, true);      // Palindrome
    all_passed &= test({1, 2}, false);           // Not palindrome
    all_passed &= test({1}, true);               // Single node
    all_passed &= test({}, true);                // Empty list is considered palindrome
    all_passed &= test({1, 2, 3, 2, 1}, true);    // Odd length palindrome
    all_passed &= test({1, 2, 3, 3, 2, 1}, true); // Even length palindrome
    all_passed &= test({1, 2, 3, 4, 2, 1}, false);// Not palindrome

    if (all_passed) {
        cout << "🎉 All test cases passed successfully! 🎉" << endl;
    } else {
        cout << "❌ Some test cases failed. Please check the failed cases!" << endl;
    }

    return 0;
}
