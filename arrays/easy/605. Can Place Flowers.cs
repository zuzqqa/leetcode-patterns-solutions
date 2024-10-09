/**
 * @brief Problem Statement
 * 
 * You have a long flowerbed in which some of the plots are planted, and some are not. 
 * However, flowers cannot be planted in adjacent plots. Given an integer array flowerbed containing 0's and 1's, 
 * where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the 
 * flowerbed without violating the no-adjacent-flowers rule and false otherwise.
 * 
 */

public class Solution {
    /**
     * @brief Determines if n flowers can be planted in a flowerbed without violating the no-adjacent-flowers rule.
     * 
     * @param flowerbed An array representing the flowerbed, where 0 indicates an empty spot and 1 indicates an occupied spot.
     * @param n The number of flowers to plant.
     * @return True if n flowers can be planted, false otherwise.
     */
    public bool CanPlaceFlowers(int[] flowerbed, int n) {
        int emptyCounter = 0; // Track how many flowers we have successfully planted

        // Loop through each position in the flowerbed array
        for (int i = 0; i < flowerbed.Length; i++) {
            // Check if the left spot is empty or if we're at the beginning of the array
            bool isLeftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
            // Check if the right spot is empty or if we're at the end of the array
            bool isRightEmpty = (i == flowerbed.Length - 1) || (flowerbed[i + 1] == 0);
            
            // If the current spot is empty and both adjacent spots are empty
            if (flowerbed[i] == 0 && isLeftEmpty && isRightEmpty) {
                // Place a flower in the current spot
                flowerbed[i] = 1; // Mark the spot as occupied by a flower
                emptyCounter++; // Increment the count of successfully planted flowers

                // Exit early if we've already planted enough flowers
                if (n <= emptyCounter) {
                    return true; // Return true if enough flowers are planted
                }
            }
        }
        // Return true if the number of planted flowers meets or exceeds n, otherwise return false
        return n <= emptyCounter;
    }
}
