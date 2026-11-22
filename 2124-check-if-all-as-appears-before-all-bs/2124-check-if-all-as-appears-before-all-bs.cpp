
class Solution {
public:
    bool checkString(string s) {
        bool foundB = false;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'b') {
                foundB = true;
            }
            else if (s[i] == 'a' && foundB) {
                return false;
            }
        }

        return true;
    }
};
