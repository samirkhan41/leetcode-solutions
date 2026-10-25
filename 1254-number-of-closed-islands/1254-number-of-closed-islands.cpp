
class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n ||
            grid[i][j] == 1) {
            return;
        }

        grid[i][j] = 1;

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Remove all islands connected to the boundary
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0)
                dfs(grid, i, 0);

            if (grid[i][n - 1] == 0)
                dfs(grid, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0)
                dfs(grid, 0, j);

            if (grid[m - 1][j] == 0)
                dfs(grid, m - 1, j);
        }

        // Count remaining closed islands
        int count = 0;

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};
