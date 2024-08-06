class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); // Number of rows in the matrix
        int n = matrix[0].size(); // Number of columns in the matrix
        int k = m * n; // Total number of elements in the matrix
        int l = 0, r = n - 1, u = 0, d = m - 1; // Initialize boundaries: left, right, up, down
        vector<int> ans; // Result vector to store the spiral order

        while (k != 0) { // Continue until all elements are processed
            int i = l; // Start from the left boundary

            // Traverse from left to right along the upper boundary
            while (i <= r && k > 0) {
                cout << matrix[u][i] << " "; // For debugging: print the current element
                ans.push_back(matrix[u][i++]); // Add the current element to the result vector
                k--; // Decrease the count of remaining elements
            }
            u++; // Move the upper boundary down
            i = u; // Reset the index to the new upper boundary

            // Traverse from top to bottom along the right boundary
            while (i <= d && k > 0) {
                cout << matrix[i][r] << " "; // For debugging: print the current element
                ans.push_back(matrix[i++][r]); // Add the current element to the result vector
                k--; // Decrease the count of remaining elements
            }
            r--; // Move the right boundary left
            i = r; // Reset the index to the new right boundary

            // Traverse from right to left along the lower boundary
            while (i >= l && k > 0) {
                cout << matrix[d][i] << " "; // For debugging: print the current element
                ans.push_back(matrix[d][i--]); // Add the current element to the result vector
                k--; // Decrease the count of remaining elements
            }
            d--; // Move the lower boundary up
            i = d; // Reset the index to the new lower boundary

            // Traverse from bottom to top along the left boundary
            while (i >= u && k > 0) {
                cout << matrix[i][l] << " "; // For debugging: print the current element
                ans.push_back(matrix[i--][l]); // Add the current element to the result vector
                k--; // Decrease the count of remaining elements
            }
            l++; // Move the left boundary right
        }

        return ans; // Return the result vector containing the spiral order
    }
};