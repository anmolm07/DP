/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

LINK - https://leetcode.com/problems/burst-balloons/
*/

class Solution {
public:
    int MCM(vector<int>& nums, int left,int right, vector<vector<int>>& mem)//Matrix Chain Multiplication Problem
    {
        if(left>=right)
            return 0;
    
        if(mem[left][right]!=-1)
            return mem[left][right];
    
        int max_cost=INT_MIN;
    
        for(int k=left;k<right;k++)
        {
            int total_cost=MCM(nums,left,k,mem)+MCM(nums,k+1,right,mem)+nums[left-1]*nums[k]*nums[right];
        
            max_cost=max(max_cost,total_cost);
       
            mem[left][right]=max_cost;
        }
        return mem[left][right];
    }
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
    
        int n=nums.size();
        vector<vector<int>> mem(n,vector<int>(n,-1));
    
        return MCM(nums,1,n-1,mem);
    }
};
