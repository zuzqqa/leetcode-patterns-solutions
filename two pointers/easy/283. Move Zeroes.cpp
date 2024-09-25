/**
 * @brief Problem Statement
 * 
 * Given an integer array `nums`, move all 0's to the end of it while maintaining 
 * the relative order of the non-zero elements. Note that you must do this in-place 
 * without making a copy of the array.
 */

class Solution {
public:
    /**
     * @brief Moves all zeros in the array to the end while maintaining order.
     * 
     * This method iterates through the array to collect non-zero elements at 
     * the front and then fills the rest of the array with zeros.
     * 
     * @param nums A reference to a vector of integers where zeros need to be moved.
     */
    void moveZeroes(vector<int>& nums) {
        int nonZeroIndex = 0; 

        // Early return if there are no zeros in the array
        if (count(nums.begin(), nums.end(), 0) == 0) {
            return;
        }

        // First pass: Move non-zero elements to the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZeroIndex] = nums[i]; // Place non-zero element
                nonZeroIndex++; // Increment the position for the next non-zero
            }
        }

        // Second pass: Fill the remaining elements with zeros
        for (int i = nonZeroIndex; i < nums.size(); i++) {
            nums[i] = 0; // Fill remaining positions with zeros
        }
    }
};
