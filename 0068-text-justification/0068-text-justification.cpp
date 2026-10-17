
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int letters = 0;

            // Find maximum words that fit in this line
            while (j < n &&
                   letters + words[j].size() + (j - i) <= maxWidth) {
                letters += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            // Last line or only one word: left-justified
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        line += ' ';
                    }
                }

                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int spaces = maxWidth - letters;
                int eachSpace = spaces / gaps;
                int extraSpace = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        int count = eachSpace;

                        if (k - i < extraSpace) {
                            count++;
                        }

                        line += string(count, ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};
