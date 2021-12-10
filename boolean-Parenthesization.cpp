/*

Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.



Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).


LINK - https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1


*/


class Solution{
public:
    int DP[1000][1000][2];
    int solve(string &S,int i,int j, bool isTrue)
    {
        if(i>j)
        return 0;
        if(i==j){
            if(isTrue==true)
            return DP[i][j][1] = S[i]=='T';
            else
            return DP[i][j][0] = S[i]=='F';
        }
        if(DP[i][j][isTrue]!=-1)
        return DP[i][j][isTrue];
        
        int ans=0;
        for(int k=i+1;k<j;k+=2)
        {
            int lt=DP[i][j][isTrue]!=-1?DP[i][j][isTrue]:solve(S,i,k-1,true);
            int lf=DP[i][j][isTrue]!=-1?DP[i][j][isTrue]:solve(S,i,k-1,false);
            int rt=DP[i][j][isTrue]!=-1?DP[i][j][isTrue]:solve(S,k+1,j,true);
            int rf=DP[i][j][isTrue]!=-1?DP[i][j][isTrue]:solve(S,k+1,j,false);
            if(S[k]=='&')
            {
                if(isTrue==true)
                    ans=ans+lt*rt;
                else
                    ans=ans+lf*rf+lf*rt+lt*rf;
            }
            if(S[k]=='|')
            {
                if(isTrue==true)
                    ans=ans+lt*rt+lt*rf+lf*rt;
                else
                    ans=ans+rf*lf;
            }
            if(S[k]=='^')
            {
                if(isTrue==true)
                    ans=ans+lt*rf+rt*lf;
                else
                    ans=ans+lf*rf+lt*rt;
            }
        }
        DP[i][j][isTrue]=ans%1003;
        return ans%1003;
    }
    int countWays(int N, string S){
        memset(DP,-1,sizeof(DP));
        return solve(S,0,N-1,true);
    }
};
