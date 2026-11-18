class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;

        vector<long long> up(m, 0), down(m, 0);

        for (int i = 0; i < m; i++) {
            up[i] = i;
            down[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> newUp(m, 0), newDown(m, 0);

            long long sum = 0;

            for (int i = 0; i < m; i++) {
                newUp[i] = sum;
                sum = (sum + down[i]) % MOD;
            }

            sum = 0;

            for (int i = m - 1; i >= 0; i--) {
                newDown[i] = sum;
                sum = (sum + up[i]) % MOD;
            }

            up = newUp;
            down = newDown;
        }

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return ans;
    }
};