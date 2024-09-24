/**
 * @brief Problem Statement
 * 
 * Given an array `nums` containing `n` integers, where each integer is in the range [1, n],
 * this problem requires identifying all integers within that range that do not appear in the `nums` array.
 * 
 */

class Solution {
public:
    /**
     * @brief Brute-force solution to find disappeared numbers.
     * This method checks for each number in the range [1, n] if it exists in the array.
     * 
     * @note This method may lead to time limit exceeded errors for large inputs due to its O(n^2) complexity.
     */
    vector<int> bruteForceSolution(vector<int>& nums) {
        vector<int> output;

        for (int i = 1; i <= nums.size(); i++) {
            // Check if i is present in nums using count
            if (count(nums.begin(), nums.end(), i) == 0) {
                output.push_back(i); 
            }
        }

        return output; 
    }

    /**
     * @brief Original solution using sets to find missing numbers.
     * This approach constructs sets for the input numbers and for the range [1, n],
     * then calculates the difference between the two sets.
     * 
     * @note This approach has a time complexity of O(n log n) due to sorting and set operations.
     */
    vector<int> originalSetSolution(vector<int>& nums) { 
        int n = nums.size();
        set<int> A(nums.begin(), nums.end()); // Store numbers in a set

        set<int> B; // Set for numbers from 1 to n
        for (int i = 1; i <= n; ++i) {
            B.insert(i); // Insert numbers from 1 to n into set B
        }

        vector<int> result;
        // Find difference between sets B and A
        set_difference(B.begin(), B.end(), A.begin(), A.end(), back_inserter(result));

        return result; 
    }

    /**
     * @brief Improved solution using an unordered set.
     * This method uses an unordered set for faster lookups while checking for missing numbers.
     * 
     * @note This method has a time complexity of O(n) and space complexity of O(n).
     */
    vector<int> improvedSetSolution(vector<int>& nums) {
        vector<int> output;
        unordered_set<int> numSet(nums.begin(), nums.end()); // Use unordered set for faster lookups

        for (int i = 1; i <= nums.size(); ++i) {
            if (numSet.find(i) == numSet.end()) { // Check if i is missing
                output.push_back(i); 
            }
        }

        return output;
    }

    /**
     * @brief Most efficient solution using a boolean vector.
     * This method marks the presence of numbers using a boolean array and identifies missing numbers.
     * 
     * @note This method has a time complexity of O(n) and space complexity of O(n).
     */
    vector<int> booleanArraySolution(vector<int>& nums) {
        vector<bool> seen(nums.size() + 1, false); // Initialize seen array
        vector<int> ans;

        // Mark numbers present in nums
        for (auto c : nums) seen[c] = true;

        // Identify missing numbers
        for (int i = 1; i <= nums.size(); i++) {
            if (!seen[i]) ans.push_back(i); // If not seen, add to results
        }

        return ans; 
    }
};

