class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int unique = 0;
    	int n=nums.size();
        for (int i = 0; i < n; i++) {
            unique = unique ^ nums[i];
        }
        return unique;
    }
};