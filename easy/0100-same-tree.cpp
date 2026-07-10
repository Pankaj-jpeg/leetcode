////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 100. Same Tree
// Difficulty : Easy
// Link       : https://leetcode.com/problems/same-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: depth-first search with recursive traversal | Time: O(n) | Space: O(h)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 12.7 MB
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
    void traversal(TreeNode* p,TreeNode* q,bool& flag){
        if(p == NULL && q == NULL || !flag)
            return;
        
        if((p == NULL && q != NULL) || (p != NULL && q == NULL)){
            flag = false;
            return;
        }

        if(p->val!=q->val){
            flag  = false;
            return;
        }
        traversal(p->left,q->left,flag);
        if(!flag)
            return;
        traversal(p->right,q->right,flag);
        if(!flag)
            return;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag = true;
        traversal(p,q,flag);
        return flag;
    }
};