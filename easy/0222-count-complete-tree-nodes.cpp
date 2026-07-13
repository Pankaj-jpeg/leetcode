////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 222. Count Complete Tree Nodes
// Difficulty : Easy
// Link       : https://leetcode.com/problems/count-complete-tree-nodes/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: recursive, calculate height and use binary representation | Time: O(h) | Space: O(h))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 31.2 MB
// Date       : 2026-07-13
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
    int lefth(TreeNode* root){
        int n = 0;
        while(root!=NULL){
            root = root->left;
            n++;
        }
        return n;
    }
    int righth(TreeNode* root){
        int n = 0;
        while(root!=NULL){
            root = root->right;
            n++;
        }
        return n;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int lh = lefth(root);
        int rh = righth(root);

        if(lh == rh)
            return (1 << lh) - 1;
    
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};