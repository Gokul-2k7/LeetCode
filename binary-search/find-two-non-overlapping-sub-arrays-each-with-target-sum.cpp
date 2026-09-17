class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i=0;int j=0;int sum=0;int min_val[2]={INT_MAX,INT_MAX};int flag=0;
        while(j<arr.size() && i<=j)
        {
            sum+=arr[j];
        
            if(sum==target)
            {   
                flag+=1;
                min_val[1]=min_val[0];
                min_val[0]=min(min_val[0],j-i+1);
            }
            while(sum>target)
            {
                sum-=arr[i++];
            }
            j++;
        }
        if(flag>=2) return min_val[0]+min_val[1];
        return -1;
    }
};