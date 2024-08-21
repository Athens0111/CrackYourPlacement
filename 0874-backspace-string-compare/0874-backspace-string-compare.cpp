class Solution {
public:
/* Optimized code:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;  // Pointer for string s
        int j = t.size() - 1;  // Pointer for string t

        // Traverse both strings from the end
        while (i >= 0 || j >= 0) {
            int skipS = 0, skipT = 0;

            // Process backspaces in string s
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;  // Count the backspaces
                    i--;  // Move to the next character
                } else if (skipS > 0) {
                    skipS--;  // Skip the current character as it's "erased"
                    i--;
                } else {
                    break;  // Stop if no more characters need to be skipped
                }
            }

            // Process backspaces in string t
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;  // Count the backspaces
                    j--;  // Move to the next character
                } else if (skipT > 0) {
                    skipT--;  // Skip the current character as it's "erased"
                    j--;
                } else {
                    break;  // Stop if no more characters need to be skipped
                }
            }

            // Compare characters from both strings
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;  // Characters don't match
            }

            // If one string has characters left but the other doesn't, return false
            if ((i >= 0) != (j >= 0)) {
                return false;  // One string is longer after backspace processing
            }

            // Move to the next characters
            i--;
            j--;
        }

        // If all characters match, return true
        return true;
    }
*/

    bool backspaceCompare(string s, string t) {
        int a = s.size() - 1;  // Last index of string s
        int b = t.size() - 1;  // Last index of string t
        int c = 0;  // (Unused variable - can be removed)

        // Process string s to simulate backspaces ('#') by marking characters to ignore with '@'
        for (int i = a; i > 0; i--) {
            if (s[i] == '#') {
                int x = i;  // Start at the position of '#'
                // Move backwards to find the first valid character to erase (if any)
                while (x > -1 && (s[x] == '#' || s[x] == '@'))
                    x--;
                if (x > -1)
                    s[x] = '@';  // Mark the valid character to be ignored by setting it to '@'
            }
        }

        // Process string t to simulate backspaces ('#') by marking characters to ignore with '@'
        for (int i = b; i > 0; i--) {
            if (t[i] == '#') {
                int x = i;  // Start at the position of '#'
                // Move backwards to find the first valid character to erase (if any)
                while (x > -1 && (t[x] == '#' || t[x] == '@'))
                    x--;
                if (x > -1)
                    t[x] = '@';  // Mark the valid character to be ignored by setting it to '@'
            }
        }

        // Debugging output to check the modified strings
        cout << s << " " << t << endl;

        // Compare the two processed strings
        int i = 0, j = 0;  // Pointers to traverse s and t
        while (i <= a && j <= b) {
            // Skip characters that were marked to be ignored in string s
            while (i <= a && (s[i] == '#' || s[i] == '@')) {
                i++;
            }

            // Skip characters that were marked to be ignored in string t
            while (j <= b && (t[j] == '#' || t[j] == '@')) {
                j++;
            }

            // Debugging output to check the current positions of i and j
            cout << i << ":" << j << endl;

            // If the current characters do not match, return false
            if (s[i] != t[j])
                return false;

            // Move to the next characters in both strings
            i++;
            j++;
        }

        // Ensure that all remaining characters in string s are ignored
        while (i <= a && (s[i] == '#' || s[i] == '@')) {
            i++;
        }

        // Ensure that all remaining characters in string t are ignored
        while (j <= b && (t[j] == '#' || t[j] == '@')) {
            j++;
        }

        // If there are any unprocessed characters left in either string, return false
        if (i <= a || j <= b)
            return false;

        // If both strings match after processing, return true
        return true;
    }

};