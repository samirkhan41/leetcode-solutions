
class Solution {
    multiset<long long> low, high;
    long long sumLow = 0, sumHigh = 0;

    // Balance both halves
    void balance() {

        while (low.size() > high.size() + 1) {

            long long x = *low.rbegin();

            low.erase(prev(low.end()));
            sumLow -= x;

            high.insert(x);
            sumHigh += x;
        }

        while (low.size() < high.size()) {

            long long x = *high.begin();

            high.erase(high.begin());
            sumHigh -= x;

            low.insert(x);
            sumLow += x;
        }
    }

    // Insert element
    void add(long long x) {

        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
            sumLow += x;
        }
        else {
            high.insert(x);
            sumHigh += x;
        }

        balance();
    }

    // Remove element
    void remove(long long x) {

        auto it = low.find(x);

        if (it != low.end()) {
            low.erase(it);
            sumLow -= x;
        }
        else {
            it = high.find(x);
            high.erase(it);
            sumHigh -= x;
        }

        balance();
    }

    // Minimum cost to make current window equal
    long long getCost() {

        long long median = *low.rbegin();

        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        // Step 1: Calculate cost of every window of size x
        vector<long long> cost(n - x + 1);

        low.clear();
        high.clear();

        sumLow = 0;
        sumHigh = 0;

        // First window
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }

        cost[0] = getCost();

        // Sliding window
        for (int i = x; i < n; i++) {

            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }

        // Step 2: Dynamic Programming
        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        // Select exactly k non-overlapping windows
        for (int j = 1; j <= k; j++) {

            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Skip current element
                curr[i] = curr[i - 1];

                // Select window ending at i-1
                if (i >= x && prev[i - x] != INF) {

                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
