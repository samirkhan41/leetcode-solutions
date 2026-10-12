
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";

        solve(ans, s, 0, 0, n);

        return ans;
    }

    void solve(vector<string>& ans, string s,
               int open, int close, int n) {

        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Add opening bracket
        if (open < n) {
            solve(ans, s + '(', open + 1, close, n);
        }

        // Add closing bracket
        if (close < open) {
            solve(ans, s + ')', open, close + 1, n);
        }
    }
};
