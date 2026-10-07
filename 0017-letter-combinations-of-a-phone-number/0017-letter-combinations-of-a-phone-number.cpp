class Solution {
public:

    vector<string> ans;

    string keypad[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string &digits, int index, string current) {

        // Base case
        if(index == digits.size()) {
            ans.push_back(current);
            return;
        }

        // Current digit
        int digit = digits[index] - '0';

        // Try every letter of this digit
        for(char ch : keypad[digit]) {

            current.push_back(ch);

            solve(digits, index + 1, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        ans.clear();

        solve(digits, 0, "");

        return ans;
    }
};