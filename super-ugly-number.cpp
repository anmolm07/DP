/*
A super ugly number is a positive integer whose prime factors are in the array primes.

Given an integer n and an array of integers primes, return the nth super ugly number.

The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].

LINK - https://leetcode.com/problems/super-ugly-number/

*/


class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m=primes.size();
        vector<int>num(m,1);
        int DP[n+1];
        DP[1]=1;
        for(int i=2;i<=n;i++)
        {
            DP[i]=INT_MAX;
            int x=0;
            for(int j=0;j<m;j++)
            {
                if(DP[i]>DP[num[j]]* primes[j])
                {
                    DP[i]=primes[j]*DP[num[j]];
                    x=j;
                }
            }
            for(int j=0;j<m;j++)
            {
                if(DP[i]==DP[num[j]]* primes[j])
                    num[j]++;
            }
        }
        return DP[n];
    }
};
