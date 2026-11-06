
class Solution {
public:
    vector<vector<int>> stMax, stMin;
    vector<int> lg;

    void build(vector<int>& nums) {

        int n = nums.size();

        lg.resize(n + 1, 0);

        for(int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int levels = lg[n] + 1;

        stMax.assign(levels, vector<int>(n));
        stMin.assign(levels, vector<int>(n));

        for(int i = 0; i < n; i++) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }

        for(int j = 1; j < levels; j++) {

            for(int i = 0; i + (1 << j) <= n; i++) {

                stMax[j][i] = max(
                    stMax[j - 1][i],
                    stMax[j - 1][i + (1 << (j - 1))]
                );

                stMin[j][i] = min(
                    stMin[j - 1][i],
                    stMin[j - 1][i + (1 << (j - 1))]
                );
            }
        }
    }

    int getRange(int l, int r) {

        int j = lg[r - l + 1];

        int maxi = max(
            stMax[j][l],
            stMax[j][r - (1 << j) + 1]
        );

        int mini = min(
            stMin[j][l],
            stMin[j][r - (1 << j) + 1]
        );

        return maxi - mini;
    }

    long long maxTotalValue(vector<int>& nums, int k) {

        int n = nums.size();

        build(nums);

        // {subarray value, left, right}
        priority_queue<tuple<int, int, int>> pq;

        // Insert largest subarray for every starting index
        for(int l = 0; l < n; l++) {

            int value = getRange(l, n - 1);

            pq.push({value, l, n - 1});
        }

        long long ans = 0;

        // Select top k subarrays
        while(k--) {

            auto [value, l, r] = pq.top();
            pq.pop();

            ans += value;

            // Move to previous endpoint
            if(r - 1 >= l) {

                int nextValue = getRange(l, r - 1);

                pq.push({nextValue, l, r - 1});
            }
        }

        return ans;
    }
};
