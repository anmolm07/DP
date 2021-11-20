/*

Given a string 'str' of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. Find the minimum numbers of characters we need to remove.
Note: The order of characters should be maintained.

Input: n = 7, str = "aebcbda"
Output: 2
Explanation: We'll remove 'e' and
'd' and the string become "abcba".

LINK - https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1

*/

int minDeletions(string str, int n) { 
    string str2=string(str.rbegin(),str.rend());
    int DP[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            DP[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str[i-1]==str2[j-1]){
                DP[i][j]=1+DP[i-1][j-1];
            }else{
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    return n-DP[n][n];
    
} 
