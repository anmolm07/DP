/*
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.
The diagram below shows two trees each with diameter nine, 
the leaves that form the ends of the longest path are shaded
(note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 


Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4

*/

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int diameterOpt(struct Node* root,int &height){
        int l = 0, r= 0;
  
        if (root == NULL) {
            return 0; 
        }
        l = diameterOpt(root->left, height);
        r = diameterOpt(root->right, height);
  
        int temp = max(l, r) + 1;
        int ans=max(temp,1+l+r);
        height= max(height,ans);
        return temp;
    }
    int diameter(Node* root) {
        int height=INT_MIN;
        diameterOpt(root,height);
        return height;
        
        // Your code here
    }
};
