
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {

        int n = nums.size();

        // Step 1: Find indices that must be unlocked
        vector<bool> required(n, false);

        int prefixMax = 0;

        for (int i = 0; i < n - 1; i++) {

            prefixMax = max(prefixMax, nums[i]);

            // If elements need to cross this boundary
            if (prefixMax > i + 1) {
                required[i] = true;
                required[i + 1] = true;
            }
        }

        // Step 2: Count required unlock operations
        int unlocks = 0;

        for (int i = 0; i < n; i++) {
            if (required[i] && locked[i] == 1) {
                unlocks++;
            }
        }

        if (unlocks > k) {
            return -1;
        }

        // Step 3: Count inversions (minimum adjacent swaps)
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (nums[i] > nums[j]) {
                    swaps++;
                }
            }
        }

        return unlocks + swaps;
    }
};
