/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

LINK- https://leetcode.com/problems/shortest-common-supersequence/


*/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int DP[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                    DP[i][j]=0;
                else if(str1[i-1]==str2[j-1])
                    DP[i][j]=1+DP[i-1][j-1];
                else
                    DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
        string res;
        int i=n,j=m;
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                res.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if(DP[i-1][j] > DP[i][j-1])
            {
                res.push_back(str1[i-1]);
                i--;
            }else{
                res.push_back(str2[j-1]);
                j--;
            }
        }
        while(i>0){
            res.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            res.push_back(str2[j-1]);
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
