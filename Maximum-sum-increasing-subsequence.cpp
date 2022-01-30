/*
Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}

LINK - https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

*/

class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int>msum(n);
	    for(int i=0;i<n;i++)
	    {
	        msum[i]=arr[i];
	        for(int j=0;j<i;j++)
	        {
	            if(arr[i]>arr[j])
	            {
	                msum[i]=max(msum[i],msum[j]+arr[i]);
	            }
	        }
	    }
	    int res=INT_MIN;
	    for(int i=0;i<n;i++)
	    res=max(res,msum[i]);
	    return res;
	    // Your code goes here
	}  
};
