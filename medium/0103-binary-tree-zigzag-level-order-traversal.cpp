////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 103. Binary Tree Zigzag Level Order Traversal
// Difficulty : Medium
// Link       : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: depth-first search with level order traversal | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 15 MB
// Date       : 2026-07-10
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

    void trav(TreeNode* root,vector<vector<int>>& ord,int lvl){
        if(root == nullptr)
            return;

        if(ord.size() == lvl)
            ord.push_back({});
        
        ord[lvl].push_back(root->val);
        trav(root->left,ord,lvl+1);
        trav(root->right,ord,lvl+1);


    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ord;
        trav(root,ord,0);

        for(int i = 0;i<ord.size();i++){
            if(i%2 != 0){
                reverse(ord[i].begin(),ord[i].end());
            }
        }
        return ord;
    }
};