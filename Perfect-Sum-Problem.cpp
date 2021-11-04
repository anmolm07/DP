/*
Given an array arr[] of integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7

LINK- https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#

*/

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    int DP[n+1][sum+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(i==0)
	            DP[i][j]=0;
	            if(j==0)
	            DP[i][j]=1;
	        }
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            if(arr[i-1]<=j)
	            {
	                DP[i][j]=( ( (DP[i-1][j-arr[i-1]]) %1000000007) + (DP[i-1][j]%1000000007) ) %1000000007;
	            }
	            else{
	                DP[i][j]=(DP[i-1][j] %1000000007);
	            }
	        }
	    }
	    return DP[n][sum];
	}
	  
};
