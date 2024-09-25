/**
 * @brief Problem Statement
 * 
 * Given an integer array `nums`, return an array `answer` such that 
 * `answer[i]` is equal to the product of all the elements of `nums` 
 * except `nums[i]`.
 * 
 * The product of any prefix or suffix of `nums` is guaranteed to fit 
 * in a 32-bit integer.
 * 
 * You must write an algorithm that runs in O(n) time and without 
 * using the division operation.
 */
class Solution {
public:
    /**
     * @brief Constructs the product array except self.
     * 
     * This method calculates the product of all elements except the
     * current element using prefix and suffix products.
     * 
     * @param nums A vector of integers.
     * @return A vector of integers where each element is the product of 
     *         all elements of `nums` except for the element at that index.
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        // Step 1: Calculate prefix products
        for (int i = 1; i < nums.size(); i++) {
            ans[i] = ans[i - 1] * nums[i - 1]; // Build prefix products
        }

        // Step 2: Calculate suffix products and multiply with prefix products
        int suffix = 1; 
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= suffix; // Multiply with the current suffix
            suffix *= nums[i]; // Update suffix for the next iteration
        }

        return ans; 
    }
};
