class Solution {
public:
/*
    Recursive Approach (without memoization)
    This approach is based on the recursive relation: f(n) = f(n-1) + f(n-2)
    The time complexity of this approach is exponential (O(2^n)) because it recalculates overlapping subproblems.
    int result(int n, vector<int> &dp){
        // Base cases: If there is 1 or 2 step, the number of ways to reach the top is n itself
        if(n==1 || n==2)
            return n;

        // If we have already calculated the result for this step, return the cached value
        if(dp[n] != -1)
            return dp[n];
            
        // Recursively calculate the result for current step using the results for previous two steps
        return dp[n] = result(n-1, dp) + result(n-2, dp);
    }

    int climbStairs(int n){
        // Initialize a dp array to store the intermediate results, with initial values set to -1 (uncomputed)
        vector<int> dp(n+1, -1);

        // Call the recursive function to compute the result for the given number of stairs
        return result(n, dp);
    }
*/

/*
    Recursive Approach (without memoization)
    This approach also uses the same recursive relation as above but doesn't store intermediate results, so it is less efficient.
    int climbStairs(int n){
        // Base cases: If there is 1 or 2 step, the number of ways to reach the top is n itself
        if(n==1 || n==2)
            return n;
            
        // Recursively calculate the result for current step using the results for previous two steps
        return climbStairs(n-1) + climbStairs(n-2);
    }

*/

    /* Iterative Approach (Bottom-Up DP)
    * This approach uses an iterative method to compute the result in a bottom-up manner.
    * It avoids recursion and stores only the last two results at a time, reducing space complexity to O(1).
    * The time complexity is O(n).
    */
    int climbStairs(int n) {
        // Base cases: If there is 1 or 2 step, the number of ways to reach the top is n itself
        if(n == 1 || n == 2)
            return n;

        // Initialize the variables to store the number of ways to reach the previous two steps
        long long prev = 1;  // The number of ways to reach step 1
        long long mid = 2;   // The number of ways to reach step 2
        long long curr;      // Variable to store the current step's result

        // Iterate from step 3 to step n and calculate the result
        for(int i = 2; i <= n; i++){
            // The number of ways to reach the current step is the sum of the ways to reach the previous two steps
            curr = prev + mid;

            // Update the variables for the next iteration
            prev = mid;
            mid = curr;
        }

        // Return the number of ways to reach the nth step
        return prev;
    }

};