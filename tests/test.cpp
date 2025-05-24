import sys
import os

# Ensure Python finds the 'solutions' folder where solution.py is located
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'solutions')))

from solution import Solution, ListNode

def build_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

def test_case(arr, expected):
    head = build_linked_list(arr)
    sol = Solution()
    result = sol.isPalindrome(head)
    print(f"Input: {arr}")
    print(f"Output: {result}")
    print(f"Expected: {expected}")
    if result == expected:
        print("✅ Test Passed!")
        return True
    else:
        print("❌ Test Failed!")
        return False

if __name__ == "__main__":
    test_cases = [
        ([1,2,2,1], True),
        ([1,2], False),
        ([1], True),
        ([], True),
        ([1,2,3,2,1], True),
        ([1,2,3,3,2,1], True),
        ([1,2,3,4,2,1], False),

        # Additional test cases
        ([1,1,1,1,1], True),            # all same elements
        ([1,2,3,4,3,2,1], True),        # odd length palindrome
        ([1,2,3,4,5,2,1], False),       # odd length non-palindrome
        ([1,0,1], True),                # palindrome with zero
        ([1,0,0,1], True),              # even length palindrome with zeros
        ([1,2,3,4,5,6,7,8,9,10], False), # strictly increasing, not palindrome
        ([1,2,3,4,3,2,2], False),       # almost palindrome but last element breaks it
        ([9,9,9,9,9,9,9,9], True),     # even length all same digits
        ([1,2,3,2,1,0], False),         # palindrome + extra element at end
        ([0], True),                    # single zero element
    ]

    passed = 0
    failed = 0

    for arr, expected in test_cases:
        if test_case(arr, expected):
            passed += 1
        else:
            failed += 1
        print("-" * 40)

    print(f"\nSummary:")
    print(f"Total Test Cases: {len(test_cases)}")
    print(f"Passed: {passed}")
    print(f"Failed: {failed}")
