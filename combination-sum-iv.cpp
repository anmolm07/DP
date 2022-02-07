/*

Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.


Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

LINK - https://leetcode.com/problems/combination-sum-iv/


*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unsigned int>DP(target+1,0);
        DP[0]=1;
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=nums[j])
                    DP[i]+=DP[i-nums[j]];
            }
        }
        
        return DP[target];
    }
};
