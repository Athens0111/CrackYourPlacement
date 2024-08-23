class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        bool flag = true;  // Allows one mismatch
        
        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                // If characters don't match, try skipping one character either from the left or the right
                if (flag) {
                    // Try skipping the left character or the right character and check if either gives a palindrome
                    return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
                }
                // If already skipped a character, return false
                return false;
            }
        }
        
        return true;  // If the entire string was processed without issues, it's a valid palindrome
    }

    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};