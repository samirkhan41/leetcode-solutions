class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();

        // Step 1: Find first decreasing element from right
        int i = n - 2;

        while(i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If such element exists
        if(i >= 0) {
            
            int j = n - 1;

            while(nums[j] <= nums[i]) {
                j--;
            }

            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the remaining part
        reverse(nums.begin() + i + 1, nums.end());
    }
};