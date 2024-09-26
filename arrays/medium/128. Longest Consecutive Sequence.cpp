/**
 * @brief Problem Statement
 * 
 * Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.
 * 
 * The solution must run in O(n) time complexity.
 */

class Solution {
public:
    /**
     * @brief Finds the length of the longest consecutive sequence in the array.
     * 
     * This function uses an unordered_set to store the elements and performs 
     * O(1) average-time lookups to identify the start of a new sequence.
     * It then expands the sequence by checking consecutive numbers in the set.
     * 
     * Time complexity: O(n) since every element is processed at most once.
     * Space complexity: O(n) for the unordered_set.
     * 
     * @param nums The input array of unsorted integers.
     * @return The length of the longest consecutive sequence.
     */
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0; 

        unordered_set<int> numSet(nums.begin(), nums.end());  // O(n) to build the set
      
        int longestSequence = 1;  

        for (int num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {  // O(1) average time for set lookup
                int currentNum = num;
                int sequence = 1;  

                while (numSet.find(currentNum + 1) != numSet.end()) {  // O(1) average time for each lookup
                    currentNum++;  
                    sequence++; 
                }
              longestSequence = (longestSequence < sequence) ? sequence : longestSequence;
            }
        }

        return longestSequence; 
    }
};
