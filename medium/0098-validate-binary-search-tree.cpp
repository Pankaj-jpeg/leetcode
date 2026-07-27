////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 98. Validate Binary Search Tree
// Difficulty : Medium
// Link       : https://leetcode.com/problems/validate-binary-search-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: in-order traversal with validation | Time: O(n) | Space: O(h))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 21.8 MB
// Date       : 2026-07-27
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
    bool trav(TreeNode* root,int& prev,int& i){
        if(root == nullptr)
            return true;

        if(!trav(root->left,prev,i))
            return false;
        
        if(i > 0 && prev >= root->val)return false;

        prev = root->val;
        i++;

       
        if(!trav(root->right,prev,i))
            return false;

        return true;
        
    }
    bool isValidBST(TreeNode* root) {
        int prev;
        int i = 0;
        return trav(root,prev,i);
    }
};