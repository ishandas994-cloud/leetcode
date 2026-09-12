class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1]) return x[1] < y[1];
            if (x[0] != y[0]) return x[0] < y[0];
            return x[3] < y[3];
        });

        vector<int> pre(n);

        for (int i = 0; i < n; i++) {
            int lo = 0, hi = i - 1, ans = -1;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (a[mid][1] < a[i][0]) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            pre[i] = ans;
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(5, -1));
        vector<vector<vector<int>>> ans(n + 1, vector<vector<int>>(5));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int k = 0; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
                ans[i][k] = ans[i - 1][k];

                if (k == 0) continue;

                int p = pre[i - 1] + 1;

                if (dp[p][k - 1] == -1) continue;

                long long val = dp[p][k - 1] + a[i - 1][2];

                vector<int> cur = ans[p][k - 1];
                cur.push_back(a[i - 1][3]);
                sort(cur.begin(), cur.end());

                if (val > dp[i][k]) {
                    dp[i][k] = val;
                    ans[i][k] = cur;
                } 
                else if (val == dp[i][k]) {
                    if (ans[i][k].empty() || cur < ans[i][k]) {
                        ans[i][k] = cur;
                    }
                }
            }
        }

        vector<int> result = ans[n][0];

        for (int k = 1; k <= 4; k++) {
            if (dp[n][k] > dp[n][0]) {
                dp[n][0] = dp[n][k];
                result = ans[n][k];
            } 
            else if (dp[n][k] == dp[n][0] && ans[n][k] < result) {
                result = ans[n][k];
            }
        }

        return result;
    }
};