
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = s.size();
        int k = words.size();
        int len = words[0].size();
        int totalLen = k * len;

        if (n < totalLen) return ans;

        unordered_map<string, int> wordCount;

        for (string word : words) {
            wordCount[word]++;
        }

        for (int i = 0; i < len; i++) {
            int left = i;
            int count = 0;

            unordered_map<string, int> seen;

            for (int right = i; right + len <= n; right += len) {
                string word = s.substr(right, len);

                if (wordCount.find(word) == wordCount.end()) {
                    seen.clear();
                    count = 0;
                    left = right + len;
                    continue;
                }

                seen[word]++;
                count++;

                while (seen[word] > wordCount[word]) {
                    string leftWord = s.substr(left, len);
                    seen[leftWord]--;
                    count--;
                    left += len;
                }

                if (count == k) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, len);
                    seen[leftWord]--;
                    count--;
                    left += len;
                }
            }
        }

        return ans;
    }
};
