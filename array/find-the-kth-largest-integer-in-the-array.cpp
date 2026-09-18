class Solution {
public:

    struct Compare
    {
        bool operator()(string a,string b)
        {
            if(a.length()>b.length()) return 1;
            else if(a.length()<b.length()) return 0;
            for(int i=0;i<a.length();i++)
            {
                if(a[i]>b[i]) return 1;
                else if(a[i]<b[i]) return 0;
            }
            return 1;
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, Compare> minHeap;
        for(int i=0;i<nums.size();i++)
        {
            minHeap.push(nums[i]);
            if(minHeap.size()>k) minHeap.pop();
        }
        return minHeap.top();
    }
};