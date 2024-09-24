/**
 * @brief Problem Statement
 * 
 * Given an array `nums` containing `n` distinct numbers in the range [0, n],
 * this problem requires identifying the only number in the range that is missing from the array.
 */

class Solution {
public:
   /**
     * @brief Alternative solution using sorting to find the missing number.
     * This method sorts the array and checks for gaps between consecutive elements.
     * 
     * @return The missing number in the range [0, n].
     * 
     * @note This method has a time complexity of O(n log n) due to sorting,
     * and a space complexity of O(1) if sorting in place.
     */
    int missingNumberSorted(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 

        // Check if the last element is not equal to n (the missing number is n)
        if (nums[nums.size() - 1] != nums.size())
            return nums.size();
            
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + 1 != nums[i + 1])
                return nums[i] + 1; // Found the missing number
        }

        return 0; // Should not reach here, but just in case
    }

    /**
     * @brief Efficient solution to find the missing number using sum formula.
     * This method calculates the expected sum of the first n natural numbers
     * and subtracts the actual sum of the elements in the array.
     * 
     * @return The missing number in the range [0, n].
     * 
     * @note This method has a time complexity of O(n) and space complexity of O(1).
     */
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Calculate the expected sum of numbers from 0 to n
        int expectedSum = n * (n + 1) / 2; 

        int actualSum = 0;

        for (int num : nums) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }
};
