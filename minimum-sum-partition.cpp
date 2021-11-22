/*
Given an integer array arr of size N, the task is to divide it into 
two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11  

LINK - https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

*/

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	    }
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
	                DP[i][j]=DP[i-1][j] || DP[i-1][j-arr[i-1]];
	            }
	            else{
	                DP[i][j]=DP[i-1][j];
	            }
	        }
	    }
	    for(int i=sum/2;i>=0;i--)
	    {
	        if(DP[n][i]==1)
	        {
	            return (sum-i)-i;
	        }
	    }
	    return 0;
	} 
};
