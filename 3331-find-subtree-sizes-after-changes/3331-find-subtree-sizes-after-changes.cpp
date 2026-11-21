
class Solution {
public:
    vector<vector<int>> adj;
    vector<int> newParent;
    vector<int> last = vector<int>(26, -1);

    void dfs1(int node, string& s) {
        int ch = s[node] - 'a';

        int old = last[ch];

        if (old != -1) {
            newParent[node] = old;
        }

        last[ch] = node;

        for (int child : adj[node]) {
            dfs1(child, s);
        }

        last[ch] = old;
    }

    int dfs2(int node, vector<vector<int>>& tree, vector<int>& ans) {
        int size = 1;

        for (int child : tree[node]) {
            size += dfs2(child, tree, ans);
        }

        ans[node] = size;

        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.assign(n, {});
        newParent = parent;
        last.assign(26, -1);

        // Step 1: Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }


        dfs1(0, s);


        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }


        vector<int> ans(n, 0);

        dfs2(0, tree, ans);

        return ans;
    }
};
