/**
 * @brief Problem Statement
 * 
 * Given an m x n matrix, the task is to return all elements of the matrix in spiral order.
 */

class Solution {
public:
    /**
     * @brief Returns the elements of the matrix in spiral order.
     * 
     * This function traverses the matrix in a spiral order and collects 
     * the elements into an output vector until all elements are included.
     * 
     * @param matrix The input matrix of integers.
     * @return A vector containing all elements of the matrix in spiral order.
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output; 
        int rows = matrix.size(), cols = matrix[0].size(); 
        int rowEnd = cols - 1, colEnd = rows - 1;
        int verticalShiftLeft = 0, verticalShiftRight = 0;
        int horizontalShiftUp = 0, horizontalShiftDown = 0; 

        // Continue until all elements are added to the output
        while(output.size() < rows * cols){
            // Traverse the top row from left to right
            for(int j = verticalShiftLeft; j < cols - verticalShiftRight; j++){ // 1st row
                output.push_back(matrix[horizontalShiftUp][j]);
            }
            horizontalShiftUp++; // Move down the top boundary

            // Traverse the last column from top to bottom
            for(int i = horizontalShiftUp; i < rows - horizontalShiftDown; i++){ // last col
                output.push_back(matrix[i][rowEnd - horizontalShiftDown]);
            }
            verticalShiftRight++; // Move in the right boundary

            // Check if the output size matches the total number of elements
            if(output.size() == rows * cols) return output;

            // Traverse the bottom row from right to left
            for(int j = rowEnd - verticalShiftRight; j >= verticalShiftLeft; j--){ // last row
                output.push_back(matrix[colEnd - horizontalShiftDown][j]);
            }
            horizontalShiftDown++; // Move up the bottom boundary

            // Check if the output size matches the total number of elements
            if(output.size() == rows * cols) return output;

            // Traverse the first column from bottom to top
            for(int i = colEnd - horizontalShiftDown; i >= horizontalShiftUp; i--){ // first col
                output.push_back(matrix[i][verticalShiftLeft]);                
            }
            verticalShiftLeft++; // Move in the left boundary
        }

        return output; 
    }
};
