class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0;
        int i=0,j=0;int n=nums.size();int res=0;int res2=0;
        while(j<n)
        {   sum+=nums[j];
            while(sum>goal)
            {   
                sum-=nums[i];
                i++;
            }
            res+=j-i+1;
            j++;
        }
        i=0;j=0;sum=0;
        goal-=1;
        while(j<n && i<=j)
        {   if(goal<0) break;
            sum+=nums[j];
            while(sum>goal)
            {   
                sum-=nums[i];
                i++;
            }
            res2+=j-i+1;
            j++;
        }
        return res-res2;
    }
};