/*
Given a list of coins of distinct denominations and total amount of money. Find the minimum number of coins required to make up that amount. Output -1 if that money cannot be made up using given coins.
You may assume that there are infinite numbers of coins of each type.

https://practice.geeksforgeeks.org/problems/min-coin5549/1
*/

class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    int n= nums.size();
	    int DP[n+1][amount+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=amount;j++)
	        {
	            if(i==0)
	            DP[i][j]=INT_MAX-1;
	            else if(j==0)
	            DP[i][j]=0;
	        }
	    }
	    for(int i=1;i<=amount;i++)
	    {
	         if(i%nums[0]==0)
	         {
	             DP[1][i]=i/nums[0];
	         }
	         else{
	             DP[1][i]=INT_MAX-1;
	         }
	    }
	    for(int i=2;i<=n;i++)
	    {
	        for(int j=1;j<=amount;j++)
	        {
	            if(nums[i-1]<=j)
	            {
	                DP[i][j]=min(DP[i-1][j] ,1 + DP[i][j-nums[i-1]] );
	            }
	            else{
	                DP[i][j]=DP[i-1][j];
	            }
	        }
	    }
	    return DP[n][amount]>=INT_MAX-1 ? -1 :DP[n][amount];
	}
};
