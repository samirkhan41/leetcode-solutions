
class Solution {
public:
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, bit;
    int timer = 0, LOG;

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[u][0] = p;

        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    void updateBIT(int i, int val) {
        while (i < (int)bit.size()) {
            bit[i] ^= val;
            i += i & -i;
        }
    }

    int queryBIT(int i) {
        int res = 0;

        while (i > 0) {
            res ^= bit[i];
            i -= i & -i;
        }

        return res;
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});
        tin.resize(n);
        tout.resize(n);
        depth.assign(n, 0);

        timer = 0;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(n, vector<int>(LOG, 0));

        dfs(0, 0);

        bit.assign(n + 2, 0);

        // Initialize Fenwick Tree
        for (int u = 0; u < n; u++) {
            int mask = 1 << (s[u] - 'a');

            updateBIT(tin[u], mask);
            updateBIT(tout[u] + 1, mask);
        }

        vector<bool> ans;

        for (string& q : queries) {
            stringstream ss(q);
            string type;
            int u, v;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (c - 'a');
                int diff = oldMask ^ newMask;

                if (diff != 0) {
                    updateBIT(tin[u], diff);
                    updateBIT(tout[u] + 1, diff);
                    s[u] = c;
                }
            } else {
                ss >> v;

                int lca = getLCA(u, v);

                int maskU = queryBIT(tin[u]);
                int maskV = queryBIT(tin[v]);

                // Correct path XOR formula
                int pathMask = maskU ^ maskV
                    ^ (1 << (s[lca] - 'a'));

                // At most one character can have odd frequency
                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};

