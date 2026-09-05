class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> s;int maxh=0;
        int n=heights.size();
        vector<int> ans(n,0);
        if(heights[n-1]) s.push(heights[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(maxh<heights[i]) maxh=heights[i];
            while(!s.empty() && s.top()<heights[i])
            {
                s.pop();
                ans[i]+=1;
            }
            if(s.empty()) 
            {   s.push(heights[i]);
                continue;
            }
            s.push(heights[i]);
            ans[i]+=1;
        }
        return ans;
    }
};