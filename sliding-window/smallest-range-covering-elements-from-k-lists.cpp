class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        vector<pair<int,int>> v;
        unordered_map<int,int> d;
        vector<int> ans;int a,b;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                minHeap.push({nums[i][j],i});
            }
        }
        while(!minHeap.empty())
        {
            v.push_back(minHeap.top());
            minHeap.pop();
        }
        int i=0;
        int min_size=INT_MAX;
        for(int j=0;j<v.size();j++)
        {
            d[v[j].second] +=1;
            while(d.size()==nums.size())
            {
                d[v[i].second] -=1;
                if(d[v[i].second]==0) d.erase(v[i].second);
                if(min_size>v[j].first-v[i].first)
                {
                    min_size=v[j].first-v[i].first;
                    a=i;
                    b=j;
                }
                i++;
            }
        }
        return {v[a].first,v[b].first};
    }
};