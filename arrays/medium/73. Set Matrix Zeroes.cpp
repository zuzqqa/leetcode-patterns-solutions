/**
 * @brief Problem Statement
 * 
 * Given an m x n integer matrix, if any element is 0, the task is to set its entire row and column to 0.
 * The solution must be performed in place, meaning no additional matrix or excessive space usage is allowed.
 * 
 * The solution leverages the first row and column of the matrix as markers to indicate which rows or columns
 * need to be zeroed out.
 */

class Solution {
public:
    /**
     * @brief Sets the entire row and column to 0 if an element is 0.
     * 
     * This function uses the first row and first column as storage for flags to avoid using extra space.
     * It handles the first row and column separately to avoid accidental overwriting.
     * 
     * @param matrix The input matrix of integers.
     */
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        bool firstRowZero = false, firstColZero = false; 

        // Check if the first row contains any zeros
        for (int j = 0; j < cols; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if the first column contains any zeros
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Use first row and first column as markers for the rest of the matrix
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0; // Mark column j to be zeroed
                    matrix[i][0] = 0; // Mark row i to be zeroed
                }
            }
        }

        // Zero out cells based on markers in the first row and column
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out the first row if needed
        if (firstRowZero) {
            for (int j = 0; j < cols; j++) {
                matrix[0][j] = 0;
            }
        }

        // Zero out the first column if needed
        if (firstColZero) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
