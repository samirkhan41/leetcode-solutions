
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string ans = "";

        // Handle negative sign
        if ((numerator < 0) ^ (denominator < 0)) {
            ans += "-";
        }

        // Convert to long long to avoid integer overflow
        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // Integer part
        ans += to_string(num / den);

        long long rem = num % den;

        if (rem == 0) return ans;

        ans += ".";

        unordered_map<long long, int> mp;

        while (rem != 0) {
            // Repeating remainder found
            if (mp.find(rem) != mp.end()) {
                ans.insert(mp[rem], "(");
                ans += ")";
                break;
            }

            mp[rem] = ans.size();

            rem *= 10;
            ans += to_string(rem / den);
            rem %= den;
        }

        return ans;
    }
};
