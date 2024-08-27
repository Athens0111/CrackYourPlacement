class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Initialize variables
        int i = 0, j = 0; // Loop indices
        int n = strs.size(); // Total number of strings in the input vector
        string ans = ""; // Variable to store the longest common prefix
        int min_size = INT_MAX; // Variable to store the length of the smallest string

        // Find the minimum size among all strings
        for (i = 0; i < n; i++) {
            // Update min_size if the current string is smaller
            if (strs[i].size() < min_size)
                min_size = strs[i].size();
        }

        // Traverse through the characters up to the minimum string size
        for (i = 0; i < min_size; i++) {
            // Get the current character from the first string as a reference
            char temp = strs[0][i];
            
            // Compare this character with the corresponding character in all other strings
            for (j = 0; j < n; j++) {
                // If any string doesn't match the reference character, return the current prefix
                if (strs[j][i] != temp)
                    return ans;
            }
            // If all strings match, append the character to the prefix
            ans += temp;
        }

        // Return the longest common prefix found
        return ans;
    }
};