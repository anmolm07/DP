/*
You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] 
which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, 
find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

LINK- https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

*/

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int DP[n+1][W+1];
        for(int i=0;i<=n;i++)
        for(int j=0;j<=W;j++)
        if(i==0 || j==0)
        DP[i][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(wt[i-1]<=j)
                {
                    DP[i][j]=max(val[i-1]+DP[i-1][j-wt[i-1]] , DP[i-1][j]);
                }
                else{
                    DP[i][j]=DP[i-1][j];
                }
            }
        }
        return DP[n][W];
    }
};
