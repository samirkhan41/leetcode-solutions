
class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check upper column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int row, vector<string>& board, int n) {
        // All queens placed successfully
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column in the current row
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';

                solve(row + 1, board, n);

                // Backtracking: remove the queen
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(0, board, n);
        return ans;
    }
};
