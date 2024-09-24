/**
 * @brief Problem Statement
 * 
 * Given a 0-indexed 1-dimensional (1D) integer array `original`, and two integers, `m` and `n`,
 * this problem requires constructing a 2-dimensional (2D) array with `m` rows and `n` columns 
 * using all the elements from `original`.
 * 
 * The elements from indices 0 to n - 1 (inclusive) of `original` should form the first row of the 
 * constructed 2D array, the elements from indices n to 2 * n - 1 (inclusive) should form the second 
 * row of the constructed 2D array, and so on.
 * 
 * Return an `m x n` 2D array constructed according to the above procedure, or an empty 2D array 
 * if it is impossible.
 */

class Solution {
public:
    /**
     * @brief Constructs a 2D array from a 1D array.
     * 
     * This method checks if it is possible to construct the 2D array based on the dimensions 
     * provided. If not, it returns an empty 2D array.
     * 
     * @param original A 1D vector of integers to be used for constructing the 2D array.
     * @param m Number of rows in the desired 2D array.
     * @param n Number of columns in the desired 2D array.
     * @return A 2D vector constructed according to the specified dimensions, or an empty 
     *         vector if the construction is impossible.
     */
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> new2DArray; 

        // Check if the total number of elements matches the desired dimensions
        if (m * n != original.size()) {
            return new2DArray;
        }

        // Reserve space for m rows to improve efficiency
        new2DArray.reserve(m);

        for (int i = 0; i < m; i++) {
            vector<int> row; // Initialize a new row vector
            row.reserve(n);  // Reserve space for n elements in the row
            int index = n * i; // Calculate the starting index for the current row

            for (int j = 0; j < n; j++) {
                row.push_back(original[index + j]); 
            }

            new2DArray.push_back(std::move(row)); 
        }

        return new2DArray;
    }
};
