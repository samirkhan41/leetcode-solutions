class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;

    vector<vector<ll>> multiply(vector<vector<ll>>& a, vector<vector<ll>>& b) {
        int n = a.size();
        vector<vector<ll>> c(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (a[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }

        return c;
    }

    vector<vector<ll>> power(vector<vector<ll>> a, ll p) {
        int n = a.size();

        vector<vector<ll>> res(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }

        while (p > 0) {
            if (p & 1) {
                res = multiply(res, a);
            }

            a = multiply(a, a);
            p >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        vector<vector<ll>> mat(sz, vector<ll>(sz, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (j < i) {
                    mat[i][m + j] = 1;
                }

                if (j > i) {
                    mat[m + i][j] = 1;
                }
            }
        }

        vector<ll> dp(sz, 0);

        for (int i = 0; i < m; i++) {
            dp[i] = i;
            dp[m + i] = m - 1 - i;
        }

        vector<vector<ll>> trans = power(mat, n - 2);

        vector<ll> ans(sz, 0);

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                ans[i] = (ans[i] + trans[i][j] * dp[j]) % MOD;
            }
        }

        ll result = 0;

        for (int i = 0; i < sz; i++) {
            result = (result + ans[i]) % MOD;
        }

        return result;
    }
};