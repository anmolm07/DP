/*
Given two strings 'str' and a wildcard pattern 'pattern' of length N and M respectively,  You have to print '1' if the wildcard pattern is matched with str else print '0' .

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

Note: The matching should cover the entire str (not partial str).

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Input:
pattern = "ba*a?"
str = "baaabab"
Output: 1
Explanation: replace '*' with "aab" and 
'?' with 'b'. 

LINK - https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1/?company[]=Amazon&company[]=Amazon&problemStatus=unsolved&problemType=functional&page=3&sortBy=submissions&query=company[]AmazonproblemStatusunsolvedproblemTypefunctionalpage3sortBysubmissionscompany[]Amazon#

LINK - https://leetcode.com/problems/wildcard-matching/


*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        bool DP[n+1][m+1];
        memset(DP,false,sizeof DP);
        DP[0][0]=true;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]=='*')
                DP[0][i]=DP[0][i-1];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(p[j-1]=='*')
                    DP[i][j]=DP[i-1][j] || DP[i][j-1];
                else if(p[j-1]=='?' || s[i-1]==p[j-1])
                {
                    DP[i][j]=DP[i-1][j-1];
                }
                else
                    DP[i][j]=false;
            }
        }
        return DP[n][m];
        
        
    }
};
