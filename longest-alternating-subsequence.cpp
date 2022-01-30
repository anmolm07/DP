/*

A sequence {x1, x2, .. xn} is alternating sequence if its elements satisfy one of the following relations :
x1 < x2 > x3 < x4 > x5..... or  x1 >x2 < x3 > x4 < x5.....
Your task is to find the longest such sequence.

Input: nums = {1,5,4}
Output: 3
Explanation: The entire sequenece is a 
alternating sequence.

LINK - https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1

*/

class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    int n=nums.size();
		    int ma=1;
		    int mi=1;
		    for(int i=1;i<n;i++)
		    {
		        if(nums[i]>nums[i-1])
		        ma=mi+1;
		        else if(nums[i]<nums[i-1])
		        mi=ma+1;
		        else 
		        continue;
		    }
		    return max(ma,mi);
		}

};
