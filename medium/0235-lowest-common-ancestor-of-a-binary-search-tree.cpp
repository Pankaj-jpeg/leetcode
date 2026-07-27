////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 235. Lowest Common Ancestor of a Binary Search Tree
// Difficulty : Medium
// Link       : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: iterative binary search tree traversal | Time: O(h) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 23 ms  |  Memory: 23.5 MB
// Date       : 2026-07-27
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
        TreeNode* node = root;

        if(p->val > q->val)
            return lowestCommonAncestor(root,q,p);

        while(node!=nullptr){
            if(p->val <= node->val && node->val <= q->val){
                break;
            }
            else if(node->val < p->val){
                node = node->right;
            }
            else
                node = node->left;
        }

        return node;
    }
};