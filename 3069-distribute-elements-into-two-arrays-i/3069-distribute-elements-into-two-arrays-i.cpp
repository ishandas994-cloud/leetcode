class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a;
        vector<int>b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(a[a.size()-1]>b[b.size()-1]){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
        }
        vector<int>temp;
        int n=a.size();
        int m=b.size();
        for(int i=0;i<n;i++){
           temp.push_back(a[i]);
        }for(int i=0;i<m;i++){
          temp.push_back(b[i]);
        }
        return temp;
    }
};