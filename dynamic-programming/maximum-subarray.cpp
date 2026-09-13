class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0;int max_end=0;int max_val=0;
        int max_arr=*max_element(nums.begin(),nums.end());
        if(max_arr<0) return max_arr;
        for(int i=0;i<nums.size();i++)
        {   
            max_val+=nums[i];
            if(max_val<0)
            {
                max_val=0;
            }
            if(max_end<max_val)
            {
                max_end=max_val;
            }
        }
        return max_end;

    }
};