/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all 
houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

LINK - https://leetcode.com/problems/house-robber-iii/


*/

class Solution {
public:
    pair<int, int> calculate(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }
        
        // DFS traversal
        pair<int, int> left = calculate(root->left);
        pair<int, int> right = calculate(root->right);
        
        pair<int, int> curr = {0, 0};
        curr.first = root->val + left.second + right.second;
        // Value without root value (Can take any value from child)
        curr.second = max(left.first, left.second) + max(right.first, right.second);
        return curr;
    }
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        pair<int, int> ans = calculate(root);
        return max(ans.first, ans.second);
        
        
    }
};
