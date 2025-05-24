import sys
import os

# Ensure Python finds the 'solutions' folder where solution.py is located
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..', 'solutions')))

from solution import Solution, ListNode  # Import ListNode as well

def build_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    return head

def print_linked_list(head):
    vals = []
    curr = head
    while curr:
        vals.append(curr.val)
        curr = curr.next
    return vals

def test_case(arr, expected):
    head = build_linked_list(arr)
    sol = Solution()
    result = sol.isPalindrome(head)
    print(f"Input: {arr}")
    print(f"Output: {result}")
    print(f"Expected: {expected}")
    print("✅ Test Passed!" if result == expected else "❌ Test Failed!")
    print("-" * 40)

if __name__ == "__main__":
    test_case([1,2,2,1], True)
    test_case([1,2], False)
    test_case([1], True)
    test_case([], True)
    test_case([1,2,3,2,1], True)
    test_case([1,2,3,3,2,1], True)
    test_case([1,2,3,4,2,1], False)
