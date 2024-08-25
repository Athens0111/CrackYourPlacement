class Solution {
public:
    // Depth-First Search (DFS) helper function to traverse the grid and mark visited cells
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j) {
        // Check if the current cell has not been visited yet
        if (!vis[i][j]) {
            // Mark the current cell as visited
            vis[i][j] = true;
            
            int m = grid[i].size(); // Number of columns
            int n = grid.size();    // Number of rows

            // Explore the adjacent cells (up, down, left, right) if they are land ('1')
            if (i - 1 >= 0 && grid[i - 1][j] == '1') // Up
                dfs(grid, vis, i - 1, j);

            if (i + 1 < n && grid[i + 1][j] == '1')  // Down
                dfs(grid, vis, i + 1, j);

            if (j - 1 >= 0 && grid[i][j - 1] == '1') // Left
                dfs(grid, vis, i, j - 1);

            if (j + 1 < m && grid[i][j + 1] == '1')  // Right
                dfs(grid, vis, i, j + 1);
        }
    }

    // Function to count the number of islands in the given grid
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns

        // Create a 2D visited array to keep track of visited cells
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0; // Counter for the number of islands

        // Traverse the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the current cell is land ('1') and hasn't been visited yet
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++;  // Increment the island counter
                    dfs(grid, vis, i, j); // Perform DFS to mark all connected land cells as visited
                }
            }
        }

        // Return the total number of islands
        return ans;
    }
};