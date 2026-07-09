////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 144. Binary Tree Preorder Traversal
// Difficulty : Easy
// Link       : https://leetcode.com/problems/binary-tree-preorder-traversal/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: iterative, using a stack to mimic recursive preorder traversal | Time: O(n) | Space: O(n)
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

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre_od;
        stack<TreeNode*> stk;
        TreeNode* node = root;
        if(node == NULL)
            return pre_od;
        while(true){
            if(node->right!=NULL)stk.push(node->right);
            if(node->left!=NULL)stk.push(node->left);
            pre_od.push_back(node->val);
            if(stk.empty()) break;
            else{
                node = stk.top();
                stk.pop();
            }
        }

        return pre_od;
    }
};