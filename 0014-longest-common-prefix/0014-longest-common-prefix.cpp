class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            
            int j = 0;

            while (j < ans.length() && 
                   j < strs[i].length() && 
                   ans[j] == strs[i][j]) {
                j++;
            }

            ans = ans.substr(0, j);

            if (ans == "") {
                return "";
            }
        }

        return ans;
    }
};