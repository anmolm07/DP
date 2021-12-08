/*


Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.

LINK - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

*/

class Solution{
public:
    int dp[1000][1000];
    int func(int arr[] ,int i, int j)
    {
        if( i == j) 
        {
            dp[i][j] = 0;
            return 0;
        }
        if(dp[i][j] != -1) 
        return dp[i][j];
        int ans = INT_MAX;
        for(int k = i;k < j;k++)
        {
            int temp = func(arr,i,k) +func(arr,k+1,j) +arr[i-1] *arr[k] *arr[j];

            ans = min(ans,temp);
        }
        dp[i][j]= ans;

        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return func(arr,1,N-1);
    }
};
