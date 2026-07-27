////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 653. Two Sum IV - Input is a BST
// Difficulty : Easy
// Link       : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Inorder traversal using two stacks | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 5 ms  |  Memory: 37.2 MB
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
    
    void push_forw(TreeNode* root,stack<TreeNode*>& stk){
        while(root!=nullptr){
            stk.push(root);
            root=root->left;
        }
    }
    void push_back(TreeNode* root,stack<TreeNode*>& stk){
        while(root!=nullptr){
            stk.push(root);
            root=root->right;
        }
    }

    int next_forw(stack<TreeNode*>& stk){
        TreeNode* node = stk.top();stk.pop();
        if(node->right!=nullptr)
            push_forw(node->right,stk);
        return node->val;
    }
    int next_back(stack<TreeNode*>& stk){
        TreeNode* node = stk.top();stk.pop();
        if(node->left!=nullptr)
            push_back(node->left,stk);
        return node->val;
    }
    bool hasNext(stack<TreeNode*>& stk){
        return !stk.empty();
    }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> forw;
        stack<TreeNode*> back;
        push_forw(root,forw);
        push_back(root,back);

        int left = next_forw(forw);
        int right = next_back(back);

        while(left<right && (hasNext(forw) && hasNext(back))){
            if(left+right == k)
                return true;
            
            if(left + right < k)
                left = next_forw(forw);
            else
                right = next_back(back);
        }

        return false;
    }
};