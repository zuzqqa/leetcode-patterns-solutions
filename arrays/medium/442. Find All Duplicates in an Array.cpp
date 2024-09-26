/**
 * @brief Problem Statement
 * 
 * Given an integer array `nums` of length `n` where all the integers of `nums` are in the range 
 * [1, n] and each integer appears once or twice, the task is to return an array of all integers 
 * that appear twice.
 * 
 * The solution must run in O(n) time complexity and utilize only constant auxiliary space,
 * excluding the space needed to store the output.
 */

class Solution {
public:
    /**
     * @brief Finds all duplicates in the given integer array.
     * 
     * This function modifies the input array to mark the integers that have been seen.
     * It utilizes the indices of the array as a way to track which numbers have already been encountered,
     * ensuring that the space usage remains constant and no extra data structures are needed.
     * 
     * @param nums The input array of integers where each integer is in the range [1, n].
     * @return A vector containing all integers that appear twice in the input array.
     */
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> output; 

        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1; // Calculate the index based on the current value

            // Check if the number at that index is positive
            if(nums[index] > 0) {
                // Mark the number as seen by making it negative
                nums[index] *= (-1);
            } else {
                // If it's already negative, we found a duplicate
                output.push_back(abs(nums[i]));
            }
        }

        return output; 
    }
};
