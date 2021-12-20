/*
You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

Input: k = 1, n = 2
Output: 2
Explanation: 
Drop the egg from floor 1. If it breaks, we know that f = 0.
Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
If it does not break, then we know f = 2.
Hence, we need at minimum 2 moves to determine with certainty what the value of f is.


LINK - https://leetcode.com/problems/super-egg-drop/
*/


class Solution {
public:
    int eggDrop(int k,int n,vector<vector<int>> &DP)
    {
        if(n==0 || n==1 || k==1)
        return DP[k][n]=n;
        if(DP[k][n]!=-1)
        return DP[k][n];
        int mn=INT_MAX;
        int l=1,h=n;
        while(l<=h)
        {
            int mid = (l+h)/2;
            int left = eggDrop(k-1,mid-1,DP);
            int right = eggDrop(k,n-mid,DP);
            
            int temp = 1 + max(left, right);
            
            if(left < right) 
                l = mid+1;
            else 
                h = mid-1;
            
            mn = min(temp, mn);
           
       }
        DP[k][n]=mn;
        return mn;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return eggDrop(k,n,dp);
    }
};
