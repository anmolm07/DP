/*
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer;
in other words, it is the product of some integer with itself.
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

LINK - https://leetcode.com/problems/perfect-squares/


*/

class Solution {
public:
    int numSquares(int n) {
        vector<int>DP(n+1,INT_MAX);
        DP[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                DP[i]=min(DP[i],1+DP[i-(j*j)]);
            }
        }
        return DP[n];
    }
};
