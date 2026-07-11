////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 199. Binary Tree Right Side View
// Difficulty : Medium
// Link       : https://leetcode.com/problems/binary-tree-right-side-view/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: level order traversal with dynamic resizing of result vector | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 14.7 MB
// Date       : 2026-07-11
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

    void trav(TreeNode* root,vector<int>& res,int lvl){
        if(root == NULL)
            return;

        if(res.size() == lvl)
            res.push_back(root->val);
        else
            res[lvl] = root->val;
        trav(root->left,res,lvl+1);
        trav(root->right,res,lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;


        trav(root,res,0);

        
        return res;
    }
};