class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;

        for (int num : nums)
            total += num;

        int target = total - x;

        if (target < 0)
            return -1;

        if (target == 0)
            return n;

        int left = 0, sum = 0, maxLen = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            if (sum == target)
                maxLen = max(maxLen, right - left + 1);
        }

        if (maxLen == -1)
            return -1;

        return n - maxLen;
    }
};