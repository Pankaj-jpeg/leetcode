////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 124. Binary Tree Maximum Path Sum
// Difficulty : Hard
// Link       : https://leetcode.com/problems/binary-tree-maximum-path-sum/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: depth-first search with dynamic maximum path sum | Time: O(n) | Space: O(h)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 28.1 MB
// Date       : 2026-07-10
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum(TreeNode* root,int& Max){
        if(root == NULL)
            return 0;
        
        int l = max(0,maxSum(root->left,Max));
        int r = max(0,maxSum(root->right,Max));

        Max = max(Max,l+root->val+r);

        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int Max = INT_MIN;

        maxSum(root,Max);

        return Max;
    }
};