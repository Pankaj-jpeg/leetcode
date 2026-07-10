////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 543. Diameter of Binary Tree
// Difficulty : Easy
// Link       : https://leetcode.com/problems/diameter-of-binary-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: depth-first search with recursive max depth calculation | Time: O(n) | Space: O(h)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 23.7 MB
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
    int maxdepth(TreeNode* root,int& Max){
        if(root == NULL)
            return 0;
        
        int l = maxdepth(root->left,Max);
        int r = maxdepth(root->right,Max);

        Max = max(Max,l+r);

        return 1 + max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int Max = 0;
        maxdepth(root,Max);
        return Max;
    }
};