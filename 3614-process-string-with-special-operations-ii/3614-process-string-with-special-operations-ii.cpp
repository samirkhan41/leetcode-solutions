
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n + 1, 0);

        // First pass: Calculate string lengths
        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                len[i + 1] = len[i] + 1;
            }
            else if (c == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (c == '#') {
                len[i + 1] = len[i] * 2;
            }
            else {
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n]) return '.';

        // Second pass: Traverse backwards
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                if (k == len[i]) {
                    return c;
                }
            }
            else if (c == '*') {
                len[i] = len[i + 1] + 1;
            }
            else if (c == '#') {
                long long prev = len[i];

                if (prev > 0) {
                    k %= prev;
                }
            }
            else if (c == '%') {
                k = len[i] - 1 - k;
            }
        }

        return '.';
    }
};
