////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 236. Lowest Common Ancestor of a Binary Tree
// Difficulty : Medium
// Link       : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: recursive DFS | Time: O(n) | Space: O(h))
// Time       : 
// Space      : 
// Runtime    : 67 ms  |  Memory: 42.4 MB
// Date       : 2026-07-11
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == nullptr)
            return nullptr;

        if(root == p)
            return p;
        if(root == q)
            return q;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left!=nullptr && right != nullptr)
            return root;
        else
            return left!=nullptr ? left : right;

    }
};