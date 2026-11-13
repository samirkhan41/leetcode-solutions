
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        long long ans = 0;
        long long cost = 0;

        int r = n - 1;

        deque<pair<long long, int>> dq;

        for (int l = n - 1; l >= 0; l--) {

            long long x = nums[l];
            int cnt = 1;

            while (!dq.empty() && dq.front().first < x) {
                cost += (x - dq.front().first) * dq.front().second;

                cnt += dq.front().second;
                dq.pop_front();
            }

            dq.push_front({x, cnt});

            while (cost > k) {
                cost -= dq.back().first - nums[r];

                dq.back().second--;

                if (dq.back().second == 0) {
                    dq.pop_back();
                }

                r--;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};
