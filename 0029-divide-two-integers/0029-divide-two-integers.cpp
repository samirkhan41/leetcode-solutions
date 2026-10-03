class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // Overflow case
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Check sign
        bool negative = (dividend < 0) ^ (divisor < 0);

        long long a = dividend;
        long long b = divisor;

        // Make both positive
        if(a < 0) a = -a;
        if(b < 0) b = -b;

        long long quotient = 0;

        while(a >= b) {
            
            long long temp = b;
            long long multiple = 1;

            // Find largest multiple of divisor
            while((temp << 1) <= a) {
                temp = temp << 1;
                multiple = multiple << 1;
            }

            a = a - temp;
            quotient = quotient + multiple;
        }

        if(negative) {
            quotient = -quotient;
        }

        return (int)quotient;
    }
};