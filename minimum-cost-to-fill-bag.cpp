/*

Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges, 
the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1

Note:
1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
2. It may be assumed that there is infinite supply of all available packet types.

Input: N = 5, arr[] = {20, 10, 4, 50, 100}
W = 5
Output: 14
Explanation: choose two oranges to minimize 
cost. First orange of 2Kg and cost 10. 
Second orange of 3Kg and cost 4. 

LINK - https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1

*/

#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        vector<int>DP(W+1,999999999);
        DP[0]=0;
        for(int i=1;i<=N;i++)
        {
            if(cost[i-1]==-1)
            continue;
            for(int j=i;j<=W;j++)
            {
                DP[j]=min(DP[j],DP[j-i]+cost[i-1]);
                
            }
        }
        return DP[W]!=999999999?DP[W]:-1;
	} 
};
