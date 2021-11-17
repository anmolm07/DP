/*

Given a rod of length N inches and an array of prices, 
price[] that contains prices of all pieces of size smaller than N.
Determine the maximum value obtainable by cutting up the rod and selling the pieces.

https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

*/

class Solution{
  public:
    int cutRod(int price[], int n) {
        int DP[n+1][n+1];
        for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        if(i==0 || j==0)
        DP[i][j]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i<=j)
                {
                    DP[i][j]=max(price[i-1]+DP[i][j-i] , DP[i-1][j]);
                }
                else{
                    DP[i][j]=DP[i-1][j];
                }
            }
        }
        return DP[n][n];
    }
};
