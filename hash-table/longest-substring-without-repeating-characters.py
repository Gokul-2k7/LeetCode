class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n=len(s)
        left=0
        d={}
        maxNumber=0
        for right in range(0,len(s)):
            
            while(s[right] in d):
                d.pop(s[left])
                left+=1
            d[s[right]]=1
            maxNumber=max(maxNumber,right-left+1)
        return maxNumber
