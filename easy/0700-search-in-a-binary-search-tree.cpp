////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 700. Search in a Binary Search Tree
// Difficulty : Easy
// Link       : https://leetcode.com/problems/search-in-a-binary-search-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: binary search tree traversal | Time: O(h) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 35.6 MB
// Date       : 2026-07-23
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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* itr = root;
        while(itr!=nullptr){
            if(itr->val == val)break;

            else if(itr->val > val)
                itr = itr->left;
            else
                itr = itr->right;
        }

        return itr;
    }
};