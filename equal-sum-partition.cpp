/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

LINK- https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
*/

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        if(sum%2==0)
        {
            sum=sum/2;
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
                        DP[i][j]= DP[i-1][j-arr[i-1]] || DP[i-1][j];
                    }
                    else{
                        DP[i][j]=DP[i-1][j];
                    }
                }
            }
            return DP[N][sum];
        }
        else
        return 0;
        
        
    }
};
