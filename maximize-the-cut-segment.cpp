/*
Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut 
length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.


Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int DP[n+1];
        DP[0]=0;
        for(int i=1;i<=n;i++)
        {
            DP[i]=-1;
            if(x<=i && DP[i-x]!=-1)
            DP[i]=max(DP[i],1+DP[i-x]);
            if(y<=i && DP[i-y]!=-1)
            DP[i]=max(DP[i],1+DP[i-y]);
            if(z<=i && DP[i-z]!=-1)
            DP[i]=max(DP[i],1+DP[i-z]);
        }
        return DP[n]==-1?0:DP[n];
    }
};


*/
