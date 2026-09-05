class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> s;
        int n=heights.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
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