/*

Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.


LINK - https://practice.geeksforgeeks.org/problems/edit-distance3702/1

*/

class Solution {
  public:
    int editDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        int DP[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0)
                DP[i][j]=j;
                else if(j==0)
                DP[i][j]=i;
                else if(s[i-1]==t[j-1])
                {
                    DP[i][j]=DP[i-1][j-1];
                }
                else{
                    DP[i][j]=1+min(DP[i-1][j],min(DP[i][j-1],DP[i-1][j-1]));
                }
            }
        }
        return DP[n][m];
    }
};
