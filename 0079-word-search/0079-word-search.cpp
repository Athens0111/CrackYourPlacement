class Solution {
public:
bool result(vector<vector<char>>& board, string word, int i, int j, int pos) {
    int n = board.size();
    int m = board[0].size();

    // If out of bounds or current cell doesn't match the current character
    if (i < 0 || j < 0 || i >= n || j >= m || board[i][j]=='*' || board[i][j] != word[pos])
        return false;
    
    // If all characters are matched
    if (pos == word.size()-1)
        return true;

    // Mark the cell as visited
    char temp = board[i][j];
    board[i][j] = '*';  // Use a special character to mark as visited
    
    // Explore all four directions
    bool found = result(board, word, i + 1, j, pos + 1) ||
                 result(board, word, i - 1, j, pos + 1) ||
                 result(board, word, i, j + 1, pos + 1) ||
                 result(board, word, i, j - 1, pos + 1);
    
    // Unmark the cell (backtrack)
    board[i][j] = temp;
    
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Start the search when the first character matches
            if (board[i][j] == word[0] && result(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}
};