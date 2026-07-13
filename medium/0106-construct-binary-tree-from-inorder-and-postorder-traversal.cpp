////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 106. Construct Binary Tree from Inorder and Postorder Traversal
// Difficulty : Medium
// Link       : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: recursive, using a map to store inorder indices | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 27.5 MB
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
    TreeNode* maker(vector<int>& postorder, vector<int>& inorder , unordered_map<int,int>& m,int post_st,int post_end,int in_st,int in_end){
        if(post_st > post_end || in_st > in_end)
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder[post_end]);

        int i = m[root->val];

        int right_ele =  in_end - i;

        root->left = maker( postorder , inorder , m , post_st , post_end - 1 - right_ele , in_st , i - 1 );
        root->right = maker( postorder , inorder , m , post_end - right_ele , post_end - 1 , i + 1 , in_end );

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i = 0;i<inorder.size();i++){
            m.insert({inorder[i],i});
        }

        return maker( postorder , inorder , m , 0 , postorder.size()-1 , 0 , inorder.size() -1 );
    }
};