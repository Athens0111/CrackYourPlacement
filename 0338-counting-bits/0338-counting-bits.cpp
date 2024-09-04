class Solution {
public:
    vector<int> countBits(int n) {
        // Base case of 0
        if(n==0)
            return {0};
        // Initialize a DP array to store the number of 1's in binary representation
        vector<int> dp(n + 1);

        // Base cases: dp[0] = 0 (0 has no 1's in its binary representation) and dp[1] = 1 (1 has one '1')
        dp[0] = 0;
        dp[1] = 1;

        // Loop through all numbers from 2 to n
        for(int i = 2; i <= n; i++) {
            // Calculate the logarithm base 2 of the current number
            double x = log2(i);

            // Check if x is an integer (i.e., i is a power of 2)
            if((x - (int)x) > 0) {
                // i is not a power of 2
                // Find the largest power of 2 smaller than i (1 << (int)x)
                int temp = 1 << ((int)x);
                
                // dp[i] is calculated as the number of 1's in i - temp plus 1
                dp[i] = dp[i - temp] + 1;
            } 
            else {
                // i is a power of 2 (e.g., 1, 2, 4, 8, ...), so it has exactly one '1' in its binary representation
                dp[i] = 1;
            }
        }

        // Return the DP array containing the number of 1's for all numbers from 0 to n
        return dp;
    }
};