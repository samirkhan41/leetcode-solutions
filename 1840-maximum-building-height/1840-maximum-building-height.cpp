
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Left to right: calculate maximum allowed heights
        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];

            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] + dist
            );
        }

        // Right to left: adjust heights
        for (int i = m - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];

            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] + dist
            );
        }

        int ans = 0;

        // Find maximum possible height between restrictions
        for (int i = 1; i < m; i++) {

            int dist = restrictions[i][0] - restrictions[i - 1][0];

            int h1 = restrictions[i - 1][1];
            int h2 = restrictions[i][1];

            int peak = (h1 + h2 + dist) / 2;

            ans = max(ans, peak);
        }

        return ans;
    }
};
