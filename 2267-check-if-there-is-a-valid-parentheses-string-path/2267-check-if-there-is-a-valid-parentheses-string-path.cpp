class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 != 0) return false;

        vector<vector<unordered_set<int>>> dp(m,
            vector<unordered_set<int>>(n));

        if (grid[0][0] == ')') return false;

        dp[0][0].insert(1);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int bal : dp[i][j]) {

                    if (i + 1 < m) {
                        int nb = bal + (grid[i + 1][j] == '(' ? 1 : -1);
                        if (nb >= 0)
                            dp[i + 1][j].insert(nb);
                    }

                    if (j + 1 < n) {
                        int nb = bal + (grid[i][j + 1] == '(' ? 1 : -1);
                        if (nb >= 0)
                            dp[i][j + 1].insert(nb);
                    }
                }
            }
        }

        return dp[m - 1][n - 1].count(0);
    }
};