#include <iostream>
#include <vector>
#include "../solutions/solution.cpp"

using namespace std;

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

void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void runTest(const vector<int>& input, bool expected, const string& testName = "") {
    static int testNum = 1;
    ListNode* head = createList(input);
    Solution sol;
    bool actual = sol.isPalindrome(head);

    cout << "Test " << testNum++ << (testName.empty() ? "" : (" - " + testName)) << ":\n";
    cout << "  Input: ";
    for (int val : input) cout << val << " ";
    cout << "\n  Expected: " << (expected ? "true" : "false");
    cout << "\n  Actual  : " << (actual ? "true" : "false");

    if (actual == expected)
        cout << " ✅ Passed\n\n";
    else
        cout << " ❌ Failed\n\n";

    deleteList(head);
}

int main() {
    runTest({}, true, "Empty list");
    runTest({1}, true, "Single element");
    runTest({1, 1}, true, "Two same");
    runTest({1, 2}, false, "Two different");
    runTest({1, 2, 1}, true, "Odd palindrome");
    runTest({1, 2, 2, 1}, true, "Even palindrome");
    runTest({1, 2, 3}, false, "Not a palindrome");
    runTest({1, 2, 3, 2, 1}, true, "Long odd palindrome");
    runTest({1, 2, 3, 4, 3, 2, 1}, true, "Longer odd");
    runTest({9, 9, 9, 9}, true, "Same digits");
    runTest({1, 2, 3, 4, 5}, false, "Straight increasing");
    runTest({-1, -2, -2, -1}, true, "Negative numbers");
}
