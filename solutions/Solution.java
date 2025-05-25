package solutions;

public class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) return true;

        // Step 1: Find the middle node (slow will point to middle)
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Step 2: Split the list into two halves
        ListNode prev = slow;       // prev points to middle node
        slow = slow.next;           // slow moves to node after middle
        prev.next = null;           // break the list here (end first half)

        // Step 3: Reverse the second half starting from slow
        ListNode temp;
        while (slow != null) {
            temp = slow.next;
            slow.next = prev;
            prev = slow;
            slow = temp;
        }
        // Now prev points to the head of reversed second half

        // Step 4: Compare the two halves
        fast = head; // pointer for first half
        slow = prev; // pointer for reversed second half
        while (slow != null) {
            if (fast.val != slow.val) return false;
            fast = fast.next;
            slow = slow.next;
        }

        return true;
    }
}
