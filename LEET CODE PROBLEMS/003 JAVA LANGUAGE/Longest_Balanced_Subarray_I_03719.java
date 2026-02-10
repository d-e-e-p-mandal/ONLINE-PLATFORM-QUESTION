// LeetCode : 3719 : Longest Balanced Subarray I

import java.util.*;

class Solution {

    // Function to find the longest subarray where
    // number of distinct even elements == number of distinct odd elements
    public int longestBalanced(int[] nums) {

        int n = nums.length;
        int window_size = 0;

        // Fix starting index
        for (int i = 0; i < n - 1; i++) {

            Set<Integer> odd = new HashSet<>();
            Set<Integer> even = new HashSet<>();

            // Extend ending index
            for (int j = i; j < n; j++) {

                if (nums[j] % 2 == 0)
                    even.add(nums[j]);
                else
                    odd.add(nums[j]);

                // Check balance condition
                if (odd.size() == even.size())
                    window_size = Math.max(window_size, j - i + 1);
            }
        }

        return window_size;
    }
}

/* Optional main() for testing */
class Longest_Balanced_Subarray_I_03719 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] nums = new int[n];

        for (int i = 0; i < n; i++)
            nums[i] = sc.nextInt();

        Solution obj = new Solution();
        System.out.println(obj.longestBalanced(nums));
    }
}

/*
-----------------------------------------
Sample Input:
6
1 2 3 4 5 6

Sample Output:
6

Explanation:
Odd numbers  = {1,3,5}
Even numbers = {2,4,6}
Both have equal distinct counts (3).

-----------------------------------------
Another Example:
Input:
5
1 1 2 2 3

Output:
4

-----------------------------------------
Time Complexity:
O(n^2)
Reason:
Two nested loops over the array.
Set operations are O(1) on average.

-----------------------------------------
Space Complexity:
O(n)
Reason:
HashSets store distinct odd and even elements.

-----------------------------------------
*/