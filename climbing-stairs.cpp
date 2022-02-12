/*

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

LINK - https://leetcode.com/problems/climbing-stairs/

*/

class Solution {
public:
    int climbStairs(int n) {
        int DP[n+1];
        if(n<=2)
            return n;
        DP[0]=0;
        DP[1]=1;  
        DP[2]=2;
        for(int i=3;i<=n;i++)
        {
            DP[i]=DP[i-1]+DP[i-2];
        }
        return DP[n];
    }
};
