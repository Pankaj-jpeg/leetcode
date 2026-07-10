////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 110. Balanced Binary Tree
// Difficulty : Easy
// Link       : https://leetcode.com/problems/balanced-binary-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: recursive depth-first search with subtree balance check | Time: O(n) | Space: O(h)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 22.8 MB
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
    pair<int,bool> MaxDepth(TreeNode* node){
        if(node == NULL)
            return {0,true};
        auto l = MaxDepth(node->left);
        if(l.second == false)
            return {-1,false};
        auto r = MaxDepth(node->right);
        if(r.second == false)
            return {-1,false};
        return {1 + max(l.first,r.first), (abs(l.first-r.first)<=1)};
    }
    bool isBalanced(TreeNode* root) {
        auto it = MaxDepth(root);
        return it.second;
    }
};