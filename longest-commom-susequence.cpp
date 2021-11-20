/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.


LINK - https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

*/

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int DP[x+1][y+1];
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                if(i==0 || j==0)
                DP[i][j]=0;
            }
        }
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    DP[i][j]=1+DP[i-1][j-1];
                }
                else{
                    DP[i][j]=max( DP[i-1][j] , DP[i][j-1]);
                }
            }
        }
        return DP[x][y];
    }
};
