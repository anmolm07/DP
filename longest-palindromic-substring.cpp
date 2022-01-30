/*
Given a string s, return the longest palindromic substring in s.

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

LINK - https://leetcode.com/problems/longest-palindromic-substring/

*/

class Solution {
public:
    void helper(int &l,int &r,string &s,int &n,int &max_len,int &start)
    {
        while(l>=0 && r<n && s[l]==s[r])
        {
            int len=r-l+1;
            if(len>max_len)
            {
                max_len=len;
                start=l;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int start;
        int max_len=0;
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            helper(l,r,s,n,max_len,start);
            l=i;r=i+1;
            helper(l,r,s,n,max_len,start);
        }
        return s.substr(start,max_len);
    }
};
