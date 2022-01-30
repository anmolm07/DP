/*

Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3.


LINK - https://practice.geeksforgeeks.org/problems/ncr1019/1


*/

class Solution{
public:
    int nCr(int n, int r){
        if(r>n)
        return 0;
        else if(r==0 || r==n)
        return 1;
        int t[n+1][r+1];

       for(int i =0 ;i<n+1;i++){
          for(int j = 0 ;j<r+1;j++){
              if(i==j || j==0)
                 t[i][j] = 1;
              else {
                  t[i][j] = t[i-1][j]%1000000007 + t[i-1][j-1]%1000000007;
              }
              
          }
       }
       
       return t[n][r]%1000000007;
    }
};
