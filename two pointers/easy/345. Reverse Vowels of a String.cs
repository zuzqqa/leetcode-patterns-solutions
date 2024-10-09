/*
*
* @brief Problem Statement
*
* Given a string s, reverse only all the vowels in the string and return it.
* The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
*
*/

public class Solution {
    /*
    * @brief Reverses the vowels in a given string.
    * @param s The input string to process.
    * @return A new string with the vowels reversed.
    *
    */
    public string ReverseVowels(string s) {
        // Initialize two pointers, one at the beginning (left) and one at the end (right) of the string
        int left = 0, right = s.Length - 1;

        // Convert the string to a character array for easy manipulation
        char[] chars = s.ToCharArray();

        // Loop until the left pointer is less than the right pointer
        while (left < right) {
            // Check if the current left and right characters are vowels
            bool leftVowel = IsVowel(chars[left]);
            bool rightVowel = IsVowel(chars[right]);

            // If both characters at the left and right pointers are vowels
            if (leftVowel && rightVowel) {
                // Swap the vowels
                char temp = chars[left];
                chars[left] = chars[right];
                chars[right] = temp;

                // Move both pointers inward after swapping
                right--;
                left++;
            }
            else {
                // If the left character is not a vowel, move the left pointer to the right
                if (!leftVowel) left++;
                // If the right character is not a vowel, move the right pointer to the left
                if (!rightVowel) right--;
            }
        }

        // Convert the character array back to a string and return it
        return new string(chars);
    }
    /* 
    *
    * @brief Determines whether a character is a vowel.
    * @param c A char in question.
    * @return True if a character is a vowel, otherwise false.
    *
    */
    private bool IsVowel(char c) {
        // Convert the character to lowercase for comparison
        char toLower = char.ToLower(c);
        // Check if the character is one of the vowels
        return toLower == 'a' || toLower == 'e' || toLower == 'i' || toLower == 'o' || toLower == 'u';
    }
}
