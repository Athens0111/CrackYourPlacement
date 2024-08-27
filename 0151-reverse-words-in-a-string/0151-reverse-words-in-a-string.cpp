class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        
        // Step 1: Trim leading, trailing, and extra spaces in between
        int i = 0, j = 0;
        while (j < n) {
            // Skip leading spaces
            while (j < n && s[j] == ' ') j++;
            if (j < n && i > 0) s[i++] = ' ';  // Add one space between words
            // Copy the word
            while (j < n && s[j] != ' ') s[i++] = s[j++];
        }
        s.resize(i);  // Resize to remove trailing spaces if any
        
        // Step 2: Reverse the entire string
        reverse(s.begin(), s.end());

        // Step 3: Reverse each word in the reversed string
        int start = 0;
        for (int end = 0; end <= s.size(); ++end) {
            // When we reach the end of a word or the string
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        
        return s;
    }
};