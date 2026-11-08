
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (string &word : words) {
            int sum = 0;

            // Calculate word weight
            for (char ch : word) {
                sum += weights[ch - 'a'];
            }

            // Map remainder to reverse alphabetical order
            int rem = sum % 26;

            char mapped = 'z' - rem;

            ans += mapped;
        }

        return ans;
    }
};
