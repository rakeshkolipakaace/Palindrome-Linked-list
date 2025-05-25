package tests;

import solutions.ListNode;
import solutions.Solution;

public class Test {
    // Helper to build linked list from array
    public static ListNode buildLinkedList(int[] arr) {
        if (arr.length == 0) return null;
        ListNode head = new ListNode(arr[0]);
        ListNode current = head;
        for (int i = 1; i < arr.length; i++) {
            current.next = new ListNode(arr[i]);
            current = current.next;
        }
        return head;
    }

    // Run individual test case
    public static boolean testCase(int[] arr, boolean expected) {
        ListNode head = buildLinkedList(arr);
        Solution sol = new Solution();
        boolean result = sol.isPalindrome(head);

        System.out.println("Input: " + java.util.Arrays.toString(arr));
        System.out.println("Output: " + result + ", Expected: " + expected);
        if (result == expected) {
            System.out.println("✅ Test Passed!\n");
            return true;
        } else {
            System.out.println("❌ Test Failed!\n");
            return false;
        }
    }

    public static void main(String[] args) {
        int[][] testArrays = {
            {1,2,2,1},
            {1,2},
            {1},
            {},
            {1,2,3,2,1},
            {1,2,3,3,2,1},
            {1,2,3,4,2,1},
            {1,1,1,1,1},
            {1,2,3,4,3,2,1},
            {1,2,3,4,5,2,1},
            {1,0,1},
            {1,0,0,1},
            {1,2,3,4,5,6,7,8,9,10},
            {1,2,3,4,3,2,2},
            {9,9,9,9,9,9,9,9},
            {1,2,3,2,1,0},
            {0}
        };

        boolean[] expectedResults = {
            true,  false, true,  true,  true,  true,
            false, true,  true,  false, true,  true,
            false, false, true,  false, true
        };

        int passed = 0, failed = 0;

        for (int i = 0; i < testArrays.length; i++) {
            if (testCase(testArrays[i], expectedResults[i])) passed++;
            else failed++;
        }

        System.out.println("Summary:");
        System.out.println("Passed: " + passed + " / " + testArrays.length);
        System.out.println("Failed: " + failed);
    }
}
