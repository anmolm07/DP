/*
Given an array Arr of size N containing positive integers. 
Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.

LINK - https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1#

*/

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    int DP[n];
	    if(n==0)
	    return 0;
	    if(n==1)
	    return arr[0];
	    if(n==2)
	    return max(arr[0],arr[1]);
	    DP[0]=arr[0];
	    DP[1]=arr[1];
	    DP[2]=arr[2]+arr[0];
	    for(int i=3;i<n;i++)
	    {
	        DP[i]=arr[i]+max(DP[i-2],DP[i-3]);
	    }
	    return max(DP[n-1],DP[n-2]);
	}
};
