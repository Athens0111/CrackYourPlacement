class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        // If needle is empty, return 0 as per problem statement
        if(m == 0)
            return 0;

        int i = 0;
        
        // Loop through haystack
        while (i <= (n - m)) {
            int j = 0;
            
            // Check if needle matches haystack starting from position i
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            
            // If the entire needle was found
            if (j == m) {
                return i;
            }
            
            // Increment i to check the next starting position in haystack
            i++;
        }
        
        // If needle is not found in haystack, return -1
        return -1;
    }

};