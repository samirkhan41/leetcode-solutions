class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;

        long double base = x;
        long double ans = 1.0;

        if (N < 0) {
            base = 1.0 / base;
            N = -N;
        }

        while (N > 0) {

            if (N & 1) {
                ans *= base;
            }

            base *= base;
            N >>= 1;
        }

        return (double)ans;
    }
};