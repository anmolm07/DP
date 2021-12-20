/*

Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one leaf node to another leaf node.

Note: Here Leaf node is a node which is connected to exactly one different node.

Input:      
           3                               
         /    \                          
       4       5                     
      /  \      
    -10   4                          
Output: 16
Explanation:
Maximum Sum lies between leaf node 4 and 5.
4 + 4 + 3 + 5 = 16.

LINK - https://practice.geeksforgeeks.org/problems/maximum-path-sum/1#

*/

class Solution {
public:
    int helper(Node * root,int &res)
    {
        if(root==NULL)
        return 0;
        if(root->left==NULL && root->right==NULL)
        return root->data;
        
        int l=helper(root->left,res);
        int r=helper(root->right,res);
        if(root->left && root->right)
        {
            res=max(res,l+r+root->data);
            return max(l,r)+root->data;
        }
        return root->left ? l+root->data:r+root->data;
    }
    int maxPathSum(Node* root)
    {
        int res=INT_MIN;
        int ans= helper(root,res);
        if(res==INT_MIN)
        return ans;
        return res;
        // code here
    }
};
