/*
Given two strings. The task is to find the length of the longest common substring.

LINK - https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
*/

class Solution{
    public:
    int lcs(string S1, string S2, int n, int m,int &result)
    {
        if(n==0 || m==0)
        return 0;
        if(S1[n-1]==S2[m-1])
        {
            int m=1+lcs(S1,S2,n-1,m-1,result);
            result=max(result,m);
            return m;
        }
        else
        {
            return 0;
        }
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int result=0;
        lcs(S1,S2,n,m,result);
        return result;
    }
};
