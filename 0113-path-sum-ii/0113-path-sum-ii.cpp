class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(TreeNode* root, int sum) {
        if (root == nullptr) return;

        path.push_back(root->val);
        sum -= root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == 0) {
                ans.push_back(path);
            }
        } else {
            dfs(root->left, sum);
            dfs(root->right, sum);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear();
        path.clear();

        dfs(root, targetSum);

        return ans;
    }
};