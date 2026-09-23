class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            int curr;
            int next = 0;

            if (s[i] == 'I') curr = 1;
            else if (s[i] == 'V') curr = 5;
            else if (s[i] == 'X') curr = 10;
            else if (s[i] == 'L') curr = 50;
            else if (s[i] == 'C') curr = 100;
            else if (s[i] == 'D') curr = 500;
            else curr = 1000;

            if (i + 1 < s.length()) {
                if (s[i + 1] == 'I') next = 1;
                else if (s[i + 1] == 'V') next = 5;
                else if (s[i + 1] == 'X') next = 10;
                else if (s[i + 1] == 'L') next = 50;
                else if (s[i + 1] == 'C') next = 100;
                else if (s[i + 1] == 'D') next = 500;
                else next = 1000;
            }

            if (curr < next) {
                ans -= curr;
            } else {
                ans += curr;
            }
        }

        return ans;
    }
};