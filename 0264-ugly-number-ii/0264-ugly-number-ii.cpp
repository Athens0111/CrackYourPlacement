#define ll long long
class Solution {
public:
    int nthUglyNumber(int n) {
        // Dynamic programming array to store the first n ugly numbers
        vector<int> dp(n);
        
        // The first ugly number is always 1
        dp[0] = 1;

        // Pointers to track the next multiple of 2, 3, and 5
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;

        // Loop to generate the next ugly number until we reach n ugly numbers
        for(int i = 1; i < n; i++) {
            // Calculate potential ugly numbers from current pointers
            int multipleOf2 = dp[p2] * 2;
            int multipleOf3 = dp[p3] * 3;
            int multipleOf5 = dp[p5] * 5;

            // The next ugly number will be the smallest among the calculated multiples
            dp[i] = min(multipleOf2, min(multipleOf3, multipleOf5));

            // Increment the pointer that contributed to the next ugly number
            if(dp[i] == multipleOf2) p2++;
            if(dp[i] == multipleOf3) p3++;
            if(dp[i] == multipleOf5) p5++;
        }

        // Return the nth ugly number
        return dp[n - 1];
    }
};