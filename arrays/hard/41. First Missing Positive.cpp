/**
 * @brief Problem Statement
 * 
 * Given an unsorted integer array `nums`, return the smallest positive integer 
 * that is not present in `nums`.
 * 
 * The algorithm must run in O(n) time and use O(1) auxiliary space.
 */

class Solution {
public:
    /**
     * @brief Finds the smallest missing positive integer in the given array.
     * 
     * This function rearranges the elements of the input array such that each positive 
     * integer `x` is placed at index `x - 1`. After the rearrangement, it identifies 
     * the first index `i` where `nums[i]` is not `i + 1`, which indicates that `i + 1` 
     * is the smallest missing positive integer.
     * 
     * @param nums The input array of integers.
     * @return The smallest positive integer that is not present in the input array.
     */
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Rearranging elements in-place
        for (int i = 0; i < n; i++) {
            // Place nums[i] at its correct index if it's a valid positive integer
            while (nums[i] <= n && nums[i] > 0 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Identify the smallest missing positive integer
        for (int i = 0; i < n; i++) {
            // If nums[i] is not equal to i + 1, return the missing positive
            if (nums[i] != i + 1) {
                return i + 1; 
            }
        }

        // If all numbers from 1 to n are present, return n + 1
        return n + 1; 
    }
};
