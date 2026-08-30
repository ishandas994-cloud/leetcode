class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxidx=0;
        int minidx=0;
        int n=nums.size();
        for (int i =1; i < n; i++) {
            if (nums[i] < nums[minidx]) {
                minidx = i;
            }
             if (nums[i] > nums[maxidx]) {
                maxidx = i;
            }
        }
       
        int left=min(maxidx,minidx);
        int right=max(minidx,maxidx);
        
        int removeleft=right+1;
        int removeright=n- left;
        int removeboth=(left+1)+(n-right);

        return min({removeleft,
                    removeright,
                    removeboth
    });
    }
};