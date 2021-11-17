/*
Given an array of integers A[] of length N and an integer target.
You want to build an expression out of A by adding one of the symbols '+' and '-' before each integer in A and then concatenate all the integers.

For example, if arr = {2, 1}, you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that can be built, which evaluates to target.

https://practice.geeksforgeeks.org/problems/target-sum-1626326450/0/?fbclid=IwAR23ImBXxUeHmTcjMzmUdgir1YbdwDLQKw18XKe1rcRWpj2d5YxCaZduPwA
*/

class Solution {
  public:
    int findTargetSumWays(vector<int>&A ,int target) {
        int n=A.size();
        int sum=0;
        for(int i=0;i<n;i++)
        sum+=A[i];
        if((sum+target)%2!=0)
        return 0;
        target=(sum-target)/2;
        int DP[n+1][target+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=target;j++)
            {
                if(j==0)
                DP[i][j]=1; 
                else if(i==0)
                DP[i][j]=0;
                else if(A[i-1]<=j)
                {
                    DP[i][j]=DP[i-1][j-A[i-1]]+DP[i-1][j];
                }
                else{
                    DP[i][j]=DP[i-1][j];
                }
            }
        }
        return DP[n][target];
        
    }
};
