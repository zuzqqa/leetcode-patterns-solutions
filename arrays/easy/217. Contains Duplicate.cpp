/**
 * @brief Problem Statement
 * 
 * Given an integer array `nums`, this problem requires determining whether any value appears
 * at least twice in the array. If any duplicates exist, the function should return true; otherwise, 
 * it should return false.
 */

class Solution {
public:
    /**
     * @brief Method to determine if the array contains duplicates.
     * 
     * This approach uses an unordered set to track the elements that have been seen. As we iterate
     * through the array, we attempt to insert each element into the set. If an element is already
     * present in the set, it indicates that there is a duplicate.
     * 
     * @note This method has a time complexity of O(n), where n is the number of elements in `nums`,
     * and a space complexity of O(n) due to the storage required for the unordered set.
     * 
     * @param nums A vector of integers where we need to check for duplicates.
     * @return true if any value appears at least twice; false if every element is distinct.
     */
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end()); // Create an unordered set from the input

        return numSet.size() < nums.size(); // If the set size is less than the vector size, duplicates exist
    }
};
