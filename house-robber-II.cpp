/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

LINK- https://leetcode.com/problems/house-robber-ii/
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        int res1,res2;
        int incl=nums[0];
        int excl=0;
        for(int i=1;i<n-1;i++)
        {
            int temp=max(incl,excl);
            incl=excl+nums[i];
            excl=temp;
        }
        res1=max(incl,excl);
        incl=nums[1];
        excl=0;
        for(int i=2;i<n;i++)
        {
            int temp=max(incl,excl);
            incl=excl+nums[i];
            excl=temp;
        }
        res2=max(incl,excl);
        return max(res1,res2);
    }
};
