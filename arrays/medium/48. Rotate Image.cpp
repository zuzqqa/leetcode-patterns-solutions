/**
 * @brief Problem Statement
 * 
 * You are given an n x n 2D matrix representing an image. The task is to rotate 
 * the matrix by 90 degrees clockwise in place. This means you have to modify the 
 * input matrix directly without allocating another 2D matrix.
 */

class Solution { 
public:
    /**
     * @brief Rotates the matrix 90 degrees clockwise in place.
     * 
     * The rotation is achieved in two steps:
     * 1. Transposing the matrix (converting rows to columns and vice versa).
     * 2. Reversing each row to complete the 90-degree clockwise rotation.
     * 
     * @param matrix The input n x n 2D matrix to be rotated.
     */
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose the matrix by swapping matrix[i][j] with matrix[j][i].
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row to complete the 90-degree clockwise rotation.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
