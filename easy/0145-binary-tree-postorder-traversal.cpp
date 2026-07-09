////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 145. Binary Tree Postorder Traversal
// Difficulty : Easy
// Link       : https://leetcode.com/problems/binary-tree-postorder-traversal/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: recursive, postorder traversal from left and right subtrees | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 11.1 MB
// Date       : 2026-07-09
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
    void postorder(TreeNode* root,vector<int>& post){
        if(root==NULL)
            return;
        
        postorder(root->left,post);
        postorder(root->right,post);
        post.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;

        postorder(root,post);


        return post;   
    }
};