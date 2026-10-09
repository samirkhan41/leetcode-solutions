
class Solution {
public:
    vector<string> ans;

    void backtrack(string& s, int index, int parts, string ip) {
        // If 4 parts are formed
        if (parts == 4) {
            if (index == s.size()) {
                ip.pop_back();  // Remove last dot
                ans.push_back(ip);
            }
            return;
        }

        // Try segment lengths 1, 2, and 3
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string segment = s.substr(index, len);

            // Leading zero is not allowed
            if (len > 1 && segment[0] == '0')
                break;

            int num = stoi(segment);

            // Segment must be between 0 and 255
            if (num > 255)
                break;

            backtrack(s, index + len, parts + 1,
                      ip + segment + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();

        // Valid IP needs at least 4 and at most 12 digits
        if (s.size() < 4 || s.size() > 12)
            return ans;

        backtrack(s, 0, 0, "");
        return ans;
    }
};
