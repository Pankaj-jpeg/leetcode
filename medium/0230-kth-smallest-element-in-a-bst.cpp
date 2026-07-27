////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 230. Kth Smallest Element in a BST
// Difficulty : Medium
// Link       : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: in-order traversal with iterative approach | Time: O(n) | Space: O(h)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 24.4 MB
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
    void trav(TreeNode* root,TreeNode*& node,int& cnt,int& k){
        if(root == nullptr || cnt == k)
            return;
        

        trav(root->left,node,cnt,k);
        cnt++;
        if(cnt == k) node = root;
        trav(root->right,node,cnt,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        TreeNode* node = nullptr;
        trav(root,node,cnt,k);

        return node->val;
    }
};