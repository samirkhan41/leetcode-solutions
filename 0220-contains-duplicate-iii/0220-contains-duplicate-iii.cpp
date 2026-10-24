
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<long long> window;

        for (int i = 0; i < nums.size(); i++) {
            long long x = nums[i];

            auto it = window.lower_bound(x - valueDiff);

            if (it != window.end() && *it <= x + valueDiff) {
                return true;
            }

            window.insert(x);

            if (window.size() > indexDiff) {
                window.erase(window.find(nums[i - indexDiff]));
            }
        }

        return false;
    }
};
