
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        long long even = 1;
        long long odd = 0;
        long long ans = 0;

        int prefix = 0;

        for (int x : arr) {
            prefix += x;

            if (prefix % 2 == 0) {
                ans = (ans + odd) % MOD;
                even++;
            }
            else {
                ans = (ans + even) % MOD;
                odd++;
            }
        }

        return ans;
    }
};
