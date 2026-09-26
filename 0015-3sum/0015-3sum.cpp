class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {

            // Duplicate first element skip karo
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {

                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Duplicate left values skip
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Duplicate right values skip
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }

                else if (sum < 0) {
                    // Sum chhota hai → left badhao
                    left++;
                }

                else {
                    // Sum bada hai → right ghatao
                    right--;
                }
            }
        }

        return ans;
    }
};