class Solution {
public:

    void solve(vector<int>& candidates, int target, int index,
               vector<int>& temp, vector<vector<int>>& ans) {

        // Target complete
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // Har candidate try karo
        for (int i = index; i < candidates.size(); i++) {

            // Agar number target se bada hai
            if (candidates[i] > target)
                break;

            // Choose
            temp.push_back(candidates[i]);

            // Same i because number unlimited times use ho sakta hai
            solve(candidates, target - candidates[i], i, temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, target, 0, temp, ans);

        return ans;
    }
};