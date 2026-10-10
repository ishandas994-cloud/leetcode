
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff;
        long long total = 0;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            total += d;
            mx = max(mx, d);
        }

        long long k = (long long)k1 + k2;

        if (total <= k) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) need += d - mid;
            }

            if (need <= k) high = mid;
            else low = mid + 1;
        }

        int level = low;
        long long ans = 0;
        long long used = 0;

        for (int d : diff) {
            if (d > level) {
                used += d - level;
                ans += 1LL * level * level;
            } else {
                ans += 1LL * d * d;
            }
        }

        long long remaining = k - used;

        for (int d : diff) {
            if (remaining == 0) break;

            if (d >= level && d > 0) {
                ans -= 1LL * level * level;
                ans += 1LL * (level - 1) * (level - 1);
                remaining--;
            }
        }

        return ans;
    }
};
