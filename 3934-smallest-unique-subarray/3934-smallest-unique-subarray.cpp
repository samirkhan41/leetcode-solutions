
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n);

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
        }

        for (int k = 1; k < n; k *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;

                return ra < rb;
            });

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                int a1 = rank[a];
                int b1 = rank[b];

                int a2 = (a + k < n) ? rank[a + k] : -1;
                int b2 = (b + k < n) ? rank[b + k] : -1;

                temp[b] = temp[a] + (a1 != b1 || a2 != b2);
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        vector<int> lcp(n, 0);
        vector<int> pos(n);

        for (int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for (int i = 0; i < n; i++) {
            int p = pos[i];

            if (p == 0) continue;

            int j = sa[p - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[p] = h;

            if (h > 0) h--;
        }

        int ans = n;

        for (int p = 0; p < n; p++) {
            int i = sa[p];

            int mx = 0;

            if (p > 0)
                mx = max(mx, lcp[p]);

            if (p + 1 < n)
                mx = max(mx, lcp[p + 1]);

            int len = mx + 1;

            if (len <= n - i)
                ans = min(ans, len);
        }

        return ans;
    }
};
