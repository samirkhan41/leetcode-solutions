class Solution {
public:
    int myAtoi(string s) {
        
        int i = 0;
        int n = s.length();

        // 1. Leading spaces remove
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Sign check
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // 3. Convert digits
        long long ans = 0;

        while (i < n && s[i] >= '0' && s[i] <= '9') {
            
            ans = ans * 10 + (s[i] - '0');

            // 4. Overflow check
            if (ans * sign > INT_MAX) {
                return INT_MAX;
            }

            if (ans * sign < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        return ans * sign;
    }
};