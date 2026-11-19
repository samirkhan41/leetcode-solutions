
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> bit(2 * n + 2, 0);

        auto update = [&](int i) {
            while (i < bit.size()) {
                bit[i]++;
                i += i & -i;
            }
        };

        auto query = [&](int i) {
            int sum = 0;

            while (i > 0) {
                sum += bit[i];
                i -= i & -i;
            }

            return sum;
        };

        long long ans = 0;
        int prefix = 0;


        update(n + 1);

        for (int x : nums) {

            if (x == target) {
                prefix++;
            } else {
                prefix--;
            }

            
            ans += query(prefix + n);

         
            update(prefix + n + 1);
        }

        return ans;
    }
};
