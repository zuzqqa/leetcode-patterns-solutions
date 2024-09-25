/**
 * @brief Problem Statement
 * 
 * Given a non-empty array of integers `nums`, every element appears twice except for one. 
 * The task is to find the single element that appears only once.
 */

class Solution {
public:

    /**
     * @brief Brute-force solution using count function.
     * 
     * This method iterates over each element in the array and checks how many times it appears 
     * using the `count()` function. If an element appears exactly once, it is returned.
     * 
     * @param nums Input array of integers.
     * @return The single element that appears only once.
     * 
     * @note This approach has a time complexity of O(n^2), as `count()` has to iterate over the array 
     *       each time it is called. This is inefficient and does not meet the problem's constraints.
     */
    int singleNumberBruteForce(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            // If the current element appears only once, return it
            if(count(nums.begin(), nums.end(), nums[i]) == 1)
                return nums[i];
        }
        return 0;
    }

    /**
     * @brief Solution using an unordered map (hash map).
     * 
     * This method counts the frequency of each element using an `unordered_map` and then returns 
     * the number that appears only once.
     * 
     * @param nums Input array of integers.
     * @return The single element that appears only once.
     * 
     * @note This solution has O(n) time complexity but requires O(n) extra space to store the hash map, 
     *       making it efficient in time but not in space.
     */
    int singleNumberWithMap(vector<int>& nums) {
        unordered_map<int, int> freq;  // Hash map to count the frequency of each element
        
        // Populate the hash map
        for(int num : nums) {
            freq[num]++;
        }

        // Find the element with frequency 1
        for(int num : nums) {
            if(freq[num] == 1) {
                return num;
            }
        }

        return 0;
    }
};
