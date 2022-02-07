/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]).
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.


Input: m = 3, n = 7
Output: 28

LINK - https://leetcode.com/problems/unique-paths/

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int DP[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                    DP[i][j]=1;
                else{
                    DP[i][j]=DP[i-1][j]+DP[i][j-1];
                }
            }
        }
        return DP[n-1][m-1];
    }
};
