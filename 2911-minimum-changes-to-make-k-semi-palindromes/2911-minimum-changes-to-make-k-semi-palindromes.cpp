
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    for (int r = 0; r < d; r++) {
                        int l = r;
                        int h = (len - 1 - r) / d * d + r;

                        while (l < h) {
                            if (s[i + l] != s[i + h]) {
                                changes++;
                            }

                            l += d;
                            h -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));

        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {
                for (int j = 2 * (p - 1); j <= i - 2; j++) {
                    dp[i][p] = min(dp[i][p],
                        dp[j][p - 1] + cost[j][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};
