
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> bonus(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    bonus[i]++;
                }
            }
        }

        const int NEG = -1e9;

        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int freeItems = bonus[i];

            vector<int> ndp = dp;

            for (int r = 0; r < price && r <= budget; r++) {
                int best = NEG;

                for (int b = r; b <= budget; b += price) {
                    int t = (b - r) / price;

                    if (t > 0 && dp[b - price] != NEG) {
                        best = max(best, dp[b - price] - (t - 1));
                    }

                    if (best != NEG) {
                        ndp[b] = max(ndp[b], t + freeItems + best);
                    }
                }
            }

            dp = ndp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
