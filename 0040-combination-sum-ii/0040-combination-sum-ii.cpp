class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target, int start,
               vector<int>& temp) {

        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {

            // Duplicate skip
            if(i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted
            if(candidates[i] > target)
                break;

            // Choose
            temp.push_back(candidates[i]);

            // i + 1 because each number can be used only once
            solve(candidates, target - candidates[i], i + 1, temp);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> temp;

        solve(candidates, target, 0, temp);

        return ans;
    }
};