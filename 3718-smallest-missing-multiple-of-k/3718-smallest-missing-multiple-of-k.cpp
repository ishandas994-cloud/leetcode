class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        for (int x : nums) {
            st.insert(x);
        }
        int multiple = k;

        while (st.find(multiple) != st.end()) {
            multiple += k;
        }

        return multiple;
    }
};