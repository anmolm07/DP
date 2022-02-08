/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]


LINK - https://leetcode.com/problems/palindrome-partitioning/
*/

class Solution {
public:
    vector<vector<string>>res;
    vector<string>temp;
    int isPalindrome(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i] !=s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
    void helper(int n,string s)
    {
        if(n==s.size())
            res.push_back(temp);
            
        for(int k=n;k<s.size();k++)
        {
            if(isPalindrome(s,n,k)){
                temp.push_back(s.substr(n,k-n+1));
                helper(k+1,s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        helper(0,s);
        return res;
        
    }
};
