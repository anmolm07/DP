/*
Given a String, find the longest palindromic subsequence.
Input:
S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.

LINK - https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1

*/

class Solution{
  public:
    int longestPalinSubseq(string A) {
        int n=A.size();
        string B=string(A.rbegin(),A.rend());
        int DP[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                DP[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(A[i-1]==B[j-1])
                {
                    DP[i][j]=1+DP[i-1][j-1];
                }else{
                    DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
                }
            }
        }
        return DP[n][n];
    }
};
