////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 102. Binary Tree Level Order Traversal
// Difficulty : Medium
// Link       : https://leetcode.com/problems/binary-tree-level-order-traversal/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Breadth-First Search (BFS) using a queue | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 17.1 MB
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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lvl_od;

        TreeNode* curr = root;
        if(curr == NULL)
            return lvl_od;
        queue<TreeNode*> q;
        q.push(curr);
        while(!q.empty()){
            int size = q.size();

            vector<int> level;
            for(int i = 0;i<size;i++)
            {
                TreeNode* hi = q.front();q.pop();
                level.push_back(hi->val);
                if(hi->left!=NULL)q.push(hi->left);
                if(hi->right!=NULL)q.push(hi->right);
            }
            lvl_od.push_back(level);

        }
        return lvl_od;
    }
};