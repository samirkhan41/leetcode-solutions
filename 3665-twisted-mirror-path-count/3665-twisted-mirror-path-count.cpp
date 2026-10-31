
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;
        int N = m * n;

        vector<int> right(N, -1);
        vector<int> down(N, -1);

        // Precompute destinations
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                int id = i * n + j;

                // Move Right
                if (j + 1 < n) {
                    if (grid[i][j + 1] == 0) {
                        right[id] = i * n + (j + 1);
                    } 
                    else {
                        right[id] = down[i * n + (j + 1)];
                    }
                }

                // Move Down
                if (i + 1 < m) {
                    if (grid[i + 1][j] == 0) {
                        down[id] = (i + 1) * n + j;
                    } 
                    else {
                        down[id] = right[(i + 1) * n + j];
                    }
                }
            }
        }

        // Dynamic Programming
        vector<long long> dp(N, 0);

        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int id = i * n + j;

                if (dp[id] == 0) continue;

                // Move Right
                int r = right[id];

                if (r != -1) {
                    dp[r] = (dp[r] + dp[id]) % MOD;
                }

                // Move Down
                int d = down[id];

                if (d != -1) {
                    dp[d] = (dp[d] + dp[id]) % MOD;
                }
            }
        }

        return dp[N - 1];
    }
};
