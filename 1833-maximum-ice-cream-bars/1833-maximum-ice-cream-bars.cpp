
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(100001, 0);

        for (int x : costs) {
            freq[x]++;
        }

        int count = 0;

        for (int i = 1; i <= 100000; i++) {
            while (freq[i] > 0 && coins >= i) {
                coins -= i;
                count++;
                freq[i]--;
            }

            if (coins < i) break;
        }

        return count;
    }
};
