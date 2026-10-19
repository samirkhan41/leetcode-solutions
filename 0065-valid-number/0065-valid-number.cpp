class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool exp = false;
        bool digitAfterExp = true;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                digit = true;
                if (exp) {
                    digitAfterExp = true;
                }
            }
            else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            }
            else if (c == '.') {
                if (dot || exp) {
                    return false;
                }
                dot = true;
            }
            else if (c == 'e' || c == 'E') {
                if (exp || !digit) {
                    return false;
                }
                exp = true;
                digitAfterExp = false;
            }
            else {
                return false;
            }
        }

        return digit && digitAfterExp;
    }
};