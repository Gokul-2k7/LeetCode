class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> d1;
        unordered_map<char,int> d2;int flag=1;
        for(int i=0;i<t.size();i++)
        {
            d2[t[i]]+=1;
        }
        int i=0,j=0;int a=0,b=0,minval=INT_MAX;
        for(;j<s.size();j++)
        {
            if( d2.contains(s[j]) && d2[s[j]]>=1)
            {
                d1[s[j]]+=1;
                if(d1[s[j]]>=d2[s[j]]) flag=1;
                else flag=0;
                while(d1.size()==d2.size() && flag)
                {   
                    if(minval>j-i+1)
                    {
                        minval=j-i+1;
                        a=i;
                        b=j+1;
                    }
                    if(d1.contains(s[i]))
                    {   d1[s[i]]-=1;
                         if(d1[s[i]]==0) d1.erase(s[i]);
                    }
                    i++;
                }
            }
        }
        string str;
        for(;a<b;a++)
        {
            str+=s[a];
        }
        return str;

    }
};