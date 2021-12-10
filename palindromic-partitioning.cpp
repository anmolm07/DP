/*

Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. 
Determine the fewest cuts needed for palindrome partitioning of given string.

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".


LINK - https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

*/


class Solution{
public:
    int DP[1000][1000];
    bool isPalindrome(string String, int i, int j)
    {
        if(i>=j)
        return false;
        while(i < j)
        {
            if(String[i] != String[j])
                return false; 
            i++;
            j--;
        }
        return true;
    }
    int solve(string &str,int i,int j)
    {
        if(DP[i][j]!=-1)
        return DP[i][j];
        if(i>=j || isPalindrome(str,i,j))
        return DP[i][j]=0;
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp=solve(str,i,k)+solve(str,k+1,j)+1;
            ans=min(ans,temp);
        }
        DP[i][j]=ans;
        return ans;
    }
    int palindromicPartition(string str)
    {
        memset(DP,-1,sizeof(DP));
        return solve(str,0,str.size()-1);
    }
};
