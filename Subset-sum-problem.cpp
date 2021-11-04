/*
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

LINK -https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/

*/

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        int DP[N+1][sum+1];
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0)
                DP[i][j]=1;
                else if(i==0)
                DP[i][j]=0;
            }
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j)
                {
                    DP[i][j] = DP[i-1][j-arr[i-1]] || DP[i-1][j];
                }
                else{
                    DP[i][j]=DP[i-1][j];
                }
            }
        }
        return DP[N][sum];
    }
};
