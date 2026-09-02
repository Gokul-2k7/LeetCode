class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;vector<int> ans;
        for(int i=0;i<k;i++)
        {
            if(!q.empty() && q.back()>=nums[i]) q.push_back(i);
            else
            {
                while(!q.empty() && nums[q.back()]<nums[i])
                {
                    q.pop_back();
                }
                q.push_back(i);
            }
        }
        ans.push_back(nums[q[0]]);
        for(int i=k;i<nums.size();i++)
        {
            if(!q.empty() && q.front()<=i-k) q.pop_front();
            if(!q.empty() && q.back()>=nums[i]) q.push_back(i);
            else
            {
                while(!q.empty() && nums[q.back()]<nums[i])
                {
                    q.pop_back();
                }
                q.push_back(i);
            }
            ans.push_back(nums[q[0]]);    
        }
        return ans;
    }
};