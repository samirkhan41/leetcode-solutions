
class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {

        if (value == 1) return -1;

        // Find smallest prime factor
        int spf = value;

        for (int i = 2; 1LL * i * i <= value; i++) {
            if (value % i == 0) {
                spf = i;
                break;
            }
        }

        // Check left side feasibility
        long long leftMax = (value - spf) / 2;

        if (index > leftMax) {
            return -1;
        }

        // Calculate right side
        long long right = n - 1LL - index;

        if (right == 0) {
            return value;
        }

        return 1LL * value + spf + 2LL * (right - 1);
    }
};
