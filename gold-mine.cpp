/*
Given a gold mine called M of (n x m) dimensions. 
Each field in this mine contains a positive integer which is the amount of gold in tons.
Initially the miner can start from any row in the first column. From a given cell, the miner can move

to the cell diagonally up towards the right 
to the right
to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect.


Input: n = 3, m = 3
M = {{1, 3, 3},
     {2, 1, 4},
     {0, 6, 4}};
Output: 12
Explaination: 
The path is {(1,0) -> (2,1) -> (2,2)}.

LINK - https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1


*/

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int DP[n][m];
        memset(DP,0,sizeof(DP));
        int res=-1;
        for(int i=0;i<n;i++)
        DP[i][0]=M[i][0];
        
        for(int j=1;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                DP[i][j]=M[i][j];
                if(i-1>=0 && i+1<n)
                {
                    DP[i][j]+=max(DP[i][j-1],max(DP[i+1][j-1],DP[i-1][j-1]));
                }
                else if(i-1>=0)
                {
                    DP[i][j]+=max(DP[i][j-1],DP[i-1][j-1]);
                }
                else if(i+1<n)
                {
                    DP[i][j]+=max(DP[i][j-1],DP[i+1][j-1]);
                }
                else{
                    DP[i][j]+=DP[i][j-1];
                }
            }
        }
        for(int i=0;i<n;i++)
        res=max(res,DP[i][m-1]);
        return res;
    }
};
