////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 99. Recover Binary Search Tree
// Difficulty : Medium
// Link       : https://leetcode.com/problems/recover-binary-search-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two inorder traversals with different conditions | Time: O(n) | Space: O(h))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 60.9 MB
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

    void inorder(TreeNode* root,TreeNode*& node,TreeNode*& prev,bool& found){
        if(root == nullptr)
            return;
        
        inorder(root->left,node,prev,found);


        if(prev && root->val < prev->val && !found){
            node = prev;
            found = true;
        }
        prev = root;



        inorder(root->right,node,prev,found);
    }
    void inorder2(TreeNode* root,TreeNode*& node,TreeNode*& prev,bool& found){
        if(root == nullptr )
            return;
        
        inorder2(root->right,node,prev,found);



        if(prev && root->val > prev->val && !found){
            node = prev;
            found = true;
        }
        prev = root;



        inorder2(root->left,node,prev,found);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* node1;TreeNode* prev=nullptr;
        bool found = false;
        inorder(root,node1,prev,found);
        found = false;
        TreeNode* node2;prev = nullptr;
        inorder2(root,node2,prev,found);

        node1->val^=node2->val;
        node2->val^=node1->val;
        node1->val^=node2->val;
    }
};