/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

LINK - https://leetcode.com/problems/unique-paths-ii/

*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        int DP[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(obstacleGrid[i][j]==1)
                    DP[i][j]=0;
                else if(i==0 && j==0)
                    DP[i][j]=1;
                else if(i==0)
                    DP[i][j]=DP[i][j-1];
                else if(j==0)
                    DP[i][j]=DP[i-1][j];
                else
                    DP[i][j]=DP[i-1][j]+DP[i][j-1];
            }
        }
        return DP[n-1][m-1];
    }
};
