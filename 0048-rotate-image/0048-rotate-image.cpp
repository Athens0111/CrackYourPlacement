class Solution {
public:
    void swap(int &a, int &b) {
        // Swap the values of a and b
        int temp = a;
        a = b;
        b = temp;
    }

    void rotate(vector<vector<int>>& matrix) {
        
        int i, j;
        int n = matrix.size();  // Get the size of the matrix (n x n)

        // Step 1: Transpose the matrix
        // This means converting all rows to columns and vice versa
        for (i = 0; i < n; i++) {
            for (j = 0; j < i; j++) {
                // Swap elements at (i, j) and (j, i)
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row to achieve the final rotated matrix
        for (i = 0; i < n; i++) {
            int p = 0, q = n - 1;  // Initialize pointers for the start and end of the row
            while (p < q)
                // Swap elements from the start and end of the row moving towards the center
                swap(matrix[i][p++], matrix[i][q--]);
        }        
    }
};