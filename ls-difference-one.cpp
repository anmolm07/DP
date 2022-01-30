/*
Given an array A[] of size N, find the longest subsequence such that difference between adjacent elements is one.

Input: N = 7
A[] = {10, 9, 4, 5, 4, 8, 6}
Output: 3
Explaination: The three possible subsequences 
{10, 9, 8} , {4, 5, 4} and {4, 5, 6}.


LINK- https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1

*/

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        vector<int>DP(N,1);
        int res=1;
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(abs(A[i]-A[j])==1)
                {
                    DP[i]=max(DP[i],1+DP[j]);
                }
                
            }
            res=max(DP[i],res);
        }
        return res;
        
    }
};
