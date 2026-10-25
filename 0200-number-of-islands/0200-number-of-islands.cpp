
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= m || j >= n ||
                grid[i][j] == '0') {
                return;
            }

            grid[i][j] = '0';

            dfs(i + 1, j);
            dfs(i - 1, j);
            dfs(i, j + 1);
            dfs(i, j - 1);
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(i, j);
                }
            }
        }

        return islands;
    }
};
