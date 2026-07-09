////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 94. Binary Tree Inorder Traversal
// Difficulty : Easy
// Link       : https://leetcode.com/problems/binary-tree-inorder-traversal/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Morris Inorder Traversal | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 11 MB
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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;

        stack<TreeNode*> stk;

        TreeNode* node = root;
        if(node == NULL)
            return in;
        while(true){
            if(node!=NULL){
                stk.push(node);
                node = node->left;
            }
            else{
                if(stk.empty()) break;
                node = stk.top();
                stk.pop();
                in.push_back(node->val);
                node = node->right;
            }
        }

        return in;
    }
};