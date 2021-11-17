/*
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.

https://practice.geeksforgeeks.org/problems/coin-change2448/1

*/

class Solution {
  public:
    long long int count(int S[], int m, int n) {
        long long int  DP[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j==0)
                DP[i][j]=1;
                if(i==0)
                DP[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(S[i-1]<=j)
                {
                    DP[i][j]=DP[i][j-S[i-1]] + DP[i-1][j]; 
                }
                else{
                    DP[i][j]=DP[i-1][j];
                }
            }
        }
        return DP[m][n];
    }
};
