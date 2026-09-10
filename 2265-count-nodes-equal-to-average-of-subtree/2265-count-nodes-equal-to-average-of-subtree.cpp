class Solution {
public:
    pair<int,int> dfs(TreeNode* root, int& ans) {
        if (!root) return {0, 0};

        auto l = dfs(root->left, ans);
        auto r = dfs(root->right, ans);

        int sum = l.first + r.first + root->val;
        int cnt = l.second + r.second + 1;

        if (sum / cnt == root->val)
            ans++;

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};