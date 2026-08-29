class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> ans(n);

        int i = 0;

        while (i < n) {
            int j = i + 1;
            while (j < n && nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                j++;
            }

            vector<int> positions(idx.begin() + i, idx.begin() + j);

            sort(positions.begin(), positions.end());
            for (int k = i; k < j; k++) {
                ans[positions[k - i]] = nums[idx[k]];
            }

            i = j;
        }

        return ans;
    }
};