
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        int ans = 1;

        for (auto& [x, count] : freq) {
            if (x == 1) {
                ans = max(ans, count % 2 ? count : count - 1);
                continue;
            }

            long long curr = x;
            int len = 0;

            while (freq.count(curr) && freq.at(curr) >= 2) {
                len += 2;
                curr *= curr;

                if (curr > 1e9) break;
            }

            if (freq.count(curr) && freq.at(curr) >= 1) {
                len++;
            } else {
                len--;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};
