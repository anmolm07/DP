/*

You are given an array A of size N. The array contains integers and is of even length.
The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, 
removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum
value as 15(10 + 5)

LINK - https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

*/

class Solution{
    public:
    long long DP[1001][1001];
    long long solve(int arr[],int i,int j,long long sum)
    {
        if(j==i+1)
        return max(arr[i],arr[j]);
        
        if(DP[i][j]!=-1)
        return DP[i][j];
        
        return DP[i][j] = max( (sum-solve(arr,i+1,j,sum-arr[i]) ),
        ( sum-solve(arr,i,j-1,sum-arr[j]) ) );
    }
    long long maximumAmount(int arr[], int n){
        long long sum=0;
        for(int i=0;i<n;i++)
        sum+=arr[i];
        memset(DP,-1,sizeof DP);
        return solve(arr,0,n-1,sum);
    }
};
