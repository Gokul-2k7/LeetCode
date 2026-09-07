class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       unordered_map<int,int> d;
       int ans;int max_ans=0;
       int count=0;int i=0;
       for(int j=0;j<fruits.size();j++)
       {
            d[fruits[j]]+=1;
            while(d.size()>2) 
            {   
                d[fruits[i]]--;
                if(d[fruits[i]]==0) d.erase(fruits[i]);
                i+=1;
            }
            max_ans=max(max_ans,j-i+1);
       } 
       return max_ans;
    }
};