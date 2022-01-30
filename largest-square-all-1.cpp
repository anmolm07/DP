/*
Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explaination: The maximum size of the square
sub-matrix is 2. The matrix itself is the 
maximum sized sub-matrix in this case.

LINK - https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

*/

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int DP[n][m];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                {
                    DP[i][j]=mat[i][j];
                }
                else if(mat[i][j]==0)
                {
                    DP[i][j]=0;
                }
                else{
                    DP[i][j]=1+min({DP[i-1][j-1],DP[i-1][j],DP[i][j-1]});
                }
                ans=max(ans,DP[i][j]);
            }
        }
        return ans;
    }
};
