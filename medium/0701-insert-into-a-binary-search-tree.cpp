////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 701. Insert into a Binary Search Tree
// Difficulty : Medium
// Link       : https://leetcode.com/problems/insert-into-a-binary-search-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: iterative in-order traversal | Time: O(h) | Space: O(1))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 59.4 MB
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        TreeNode* prev;
        TreeNode* node = new TreeNode(val);
        
        if(root==nullptr){
            return node;
        }

        while(curr!=nullptr){
            prev = curr;
            if(curr->val > val){
                if(curr->left!=nullptr)
                    curr = curr->left;
                else{
                    curr->left = node;
                    break;
                }
            }
            else{
                if(curr->right != nullptr)
                    curr = curr->right;
                else{
                    curr->right = node;
                    break;
                }
            }
        }
        
        return root;

    }
};