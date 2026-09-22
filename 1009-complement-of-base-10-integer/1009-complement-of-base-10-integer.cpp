class Solution {
public:
    int bitwiseComplement(int n) {

        if(n == 0) {
            return 1;
        }

        int ans = 0;
        int place = 1;

        while(n > 0) {
            int bit = n % 2;

            if(bit == 0) {
                ans = ans + place;
            }

            n = n / 2;
            place = place * 2;
        }

        return ans;
    }
};