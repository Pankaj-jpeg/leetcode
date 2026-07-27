////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1008. Construct Binary Search Tree from Preorder Traversal
// Difficulty : Medium
// Link       : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: recursive, divide and conquer | Time: O(n log n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 16.7 MB
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
    TreeNode* maker(vector<int>& pre,vector<int>& in,int pre_st,int pre_end,int in_st,int in_end){
        if(pre_st > pre_end)
            return nullptr;
        
        int i = in_st;
        while(in[i] != pre[pre_st]){
            i++;
        }
        int left_side = i - in_st;
        TreeNode* left = maker(pre,in,pre_st + 1, pre_st + left_side ,in_st, i - 1);
        TreeNode* right = maker(pre,in,pre_st + left_side + 1,pre_end ,i + 1,in_end);
        TreeNode* node = new TreeNode(pre[pre_st],left,right);

        return node;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        int n = preorder.size();
        
        return maker(preorder,inorder,0,n-1,0,n-1);
    }
};