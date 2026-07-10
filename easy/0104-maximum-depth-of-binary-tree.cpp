////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 104. Maximum Depth of Binary Tree
// Difficulty : Easy
// Link       : https://leetcode.com/problems/maximum-depth-of-binary-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: recursive depth-first search | Time: O(n) | Space: O(h)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 22.2 MB
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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
        


    }
};