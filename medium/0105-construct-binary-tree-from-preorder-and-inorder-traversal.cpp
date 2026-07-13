////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Difficulty : Medium
// Link       : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: recursive, divide and conquer | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 2 ms  |  Memory: 27.5 MB
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

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>& m,int pre_st,int pre_end,int in_st,int in_end){
        if(pre_st > pre_end || in_st > in_end)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[pre_st]);
        int i = m[root->val];
        root->left = helper( preorder , inorder , m , pre_st + 1 , pre_st + i - in_st , in_st , i - 1 );
        root->right = helper( preorder , inorder , m , pre_st + i - in_st + 1 , pre_end , i + 1 , in_end );
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int> m;

        for(int i = 0;i<n;i++){
            m.insert({inorder[i],i});
        }
        return helper(preorder,inorder,m,0,n-1,0,n-1);
    }
};