////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 101. Symmetric Tree
// Difficulty : Easy
// Link       : https://leetcode.com/problems/symmetric-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: recursive tree traversal with mirrored nodes | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 18.6 MB
// Date       : 2026-07-11
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
    bool trav(TreeNode* p,TreeNode* q){
        if(p == nullptr && q == nullptr)
            return true;
        
        if(p == nullptr || q == nullptr || p->val!=q->val)
            return false;

        return trav(p->left,q->right) && trav(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* p = root->left;
        TreeNode* q = root->right;


        return trav(p,q);
    }
};