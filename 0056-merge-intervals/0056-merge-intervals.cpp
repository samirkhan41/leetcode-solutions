class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Sort by starting point
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(auto interval : intervals) {

            // No overlap
            if(ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            }
            
            // Overlap
            else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        return ans;
    }
};