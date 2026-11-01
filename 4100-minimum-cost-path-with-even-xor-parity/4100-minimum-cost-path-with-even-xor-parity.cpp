
class Solution {
public:
    int minActivationCost(vector<vector<int>>& edges, vector<int>& values) {

        int n = values.size();

        const long long INF = 1e18;

        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Convert values into parity
        vector<int> parity(n);

        for (int i = 0; i < n; i++) {
            parity[i] = __builtin_popcount(
                (unsigned int)values[i]
            ) % 2;
        }

        // Iterative DFS to avoid stack overflow
        vector<int> parent(n, -1);
        vector<int> order;

        order.push_back(0);

        for (int i = 0; i < order.size(); i++) {

            int u = order[i];

            for (auto &[v, w] : adj[u]) {

                if (v == parent[u]) continue;

                parent[v] = u;
                order.push_back(v);
            }
        }

        // dp[u][0] = minimum cost with even parity
        // dp[u][1] = minimum cost with odd parity

        vector<array<long long, 2>> dp(n);

        for (int u = 0; u < n; u++) {
            dp[u] = {INF, INF};
        }

        long long ans = INF;

        // Process nodes in reverse DFS order
        for (int i = n - 1; i >= 0; i--) {

            int u = order[i];

            // Single arm: node itself
            dp[u][parity[u]] = 0;

            // Best previous arms by parity
            long long best[2] = {INF, INF};

            // Node itself is the first arm
            best[parity[u]] = 0;

            for (auto &[v, w] : adj[u]) {

                if (parent[v] != u) continue;

                long long current[2] = {INF, INF};

                // Build arms through this child
                for (int p = 0; p < 2; p++) {

                    if (dp[v][p] == INF) continue;

                    int newParity = p ^ parity[u];

                    current[newParity] = min(
                        current[newParity],
                        dp[v][p] + w
                    );

                    // Update downward DP
                    dp[u][newParity] = min(
                        dp[u][newParity],
                        dp[v][p] + w
                    );
                }

                // Combine with previous DIFFERENT branches
                for (int p = 0; p < 2; p++) {

                    if (current[p] == INF) continue;

                    int need = p ^ parity[u];

                    if (best[need] != INF) {

                        ans = min(
                            ans,
                            current[p] + best[need]
                        );
                    }
                }

                // Add current child's arms for future children
                for (int p = 0; p < 2; p++) {
                    best[p] = min(best[p], current[p]);
                }
            }
        }

        return ans == INF ? -1 : (int)ans;
    }
};
