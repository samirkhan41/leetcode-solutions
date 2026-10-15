
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void backtrack(int start, vector<int>& nums) {
        ans.push_back(temp);

        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);

            backtrack(i + 1, nums);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0, nums);
        return ans;
    }
};
