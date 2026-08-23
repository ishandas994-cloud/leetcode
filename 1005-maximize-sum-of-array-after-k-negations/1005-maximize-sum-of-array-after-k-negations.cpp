class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size() && k>0;i++){
            if(nums[i]<0){
                nums[i]=-nums[i];
                k--;
            }
        }
        if(k%2==1){
            int mini=*min_element(nums.begin(),nums.end());
            return accumulate(nums.begin(),nums.end(),0)-2*mini;

        }
        return accumulate(nums.begin(),nums.end(),0);
    }
};