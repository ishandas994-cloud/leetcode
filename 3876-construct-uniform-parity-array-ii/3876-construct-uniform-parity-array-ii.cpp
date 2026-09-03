class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = INT_MAX;

        for (int x : nums1) {
            mn = min(mn, x);
        }
        if (mn % 2 == 1) {
            return true;
        }
        for (int x : nums1) {
            if (x % 2 == 1) {
                return false;
            }
        }

        return true;
    }
};