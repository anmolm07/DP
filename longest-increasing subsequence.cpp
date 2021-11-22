/*
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6

LINK - https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

*/

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        set<int> temp(a,a+n);
        vector<int>a1(temp.begin(),temp.end());
        sort(a1.begin(),a1.end());
        int m=a1.size();
        int DP[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                DP[i][j]=0;
                else if(a[i-1]==a1[j-1])
                DP[i][j]=1+DP[i-1][j-1];
                else
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
        return DP[n][m];
    }
};
