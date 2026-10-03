class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        int ans = 0;

        for(int num : st) {

            if(st.find(num - 1) == st.end()) {

                int curr = num;
                int count = 1;

                while(st.find(curr + 1) != st.end()) {
                    curr++;
                    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};