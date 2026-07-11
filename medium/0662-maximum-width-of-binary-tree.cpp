////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 662. Maximum Width of Binary Tree
// Difficulty : Medium
// Link       : https://leetcode.com/problems/maximum-width-of-binary-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: level order traversal with dynamic indexing | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 19.7 MB
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

    int widthOfBinaryTree(TreeNode* root) {
        long long Max = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long long l = 0;
            int minimum_idx = q.front().second;
            long long r = 0;
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front().first;
                long long idx = q.front().second - minimum_idx;
                if(i == 0)
                    l = idx;
                if(i == size-1)
                    r = idx;
                q.pop();
                if(node->left!=nullptr)q.push({node->left,2*idx+1});
                if(node->right!=nullptr)q.push({node->right,2*idx+2});
            }
            Max = max(Max,r-l+1);
        }

        return Max;
    }
};