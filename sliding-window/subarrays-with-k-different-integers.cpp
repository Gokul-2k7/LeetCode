class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int i=0;int j=0;
        unordered_map<int,int> d;
        int count=0;
        while(j<nums.size() && i<=j)
        {
            d[nums[j]]+=1;
           
            while(d.size()>k)
            {
                d[nums[i]]--;
                if(d[nums[i]]==0) d.erase(nums[i]);
                i++;
            }
            count+=j-i+1;
            j++;
        }
        i=0;j=0;
        d.clear();
        k--;
        while(j<nums.size() && i<=j)
        {   if(k<0) break;
            d[nums[j]]+=1;
           
            while(d.size()>k)
            {
                d[nums[i]]--;
                if(d[nums[i]]==0) d.erase(nums[i]);
                i++;
            }
            count-=j-i+1;
            j++;
        }
        return count;
    }
};