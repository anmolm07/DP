/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

LINK - https://leetcode.com/problems/maximal-square/


*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int DP[n][m];
        int res=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                    if(matrix[i][j]=='0')
                        DP[i][j]=0;
                    else
                        DP[i][j]=1;
                else if(matrix[i][j]=='0')
                    DP[i][j]=0;
                else
                    DP[i][j]=1+min({DP[i-1][j],DP[i-1][j-1],DP[i][j-1]});
                res=max(res,DP[i][j]);
            }
        }
        return res*res;
        
        
    }
};
