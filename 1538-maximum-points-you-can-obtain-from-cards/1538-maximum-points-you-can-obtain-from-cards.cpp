class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(); // Get the total number of card points
        int i = 0, j = 0; // Initialize two pointers for the sliding window
        int sum = 0; // Initialize sum for the current window
        int total = 0; // Initialize total to store the sum of all card points

        // Calculate the total sum of all card points
        for (int l = 0; l < n; l++)
            total += cardPoints[l];

        int ans = 0; // Initialize the answer to store the maximum score

        // Use a sliding window to find the minimum sum of n-k elements
        while (j < n) {
            sum += cardPoints[j]; // Add the current element to the sum

            // If the window size reaches n-k, calculate the score
            if ((j - i + 1) == (n - k)) {
                ans = max(ans, (total - sum)); // Update the answer with the maximum score
                sum -= cardPoints[i++]; // Remove the element at the start of the window
            }
            j++; // Move the window forward
        }

        // If k is equal to the size of the array, return the total sum
        if (k == n)
            return total;
        // Else return ans
        return ans;
    }
};