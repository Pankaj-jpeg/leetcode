////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 173. Binary Search Tree Iterator
// Difficulty : Medium
// Link       : https://leetcode.com/problems/binary-search-tree-iterator/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Inorder traversal using a stack | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 6 ms  |  Memory: 31.9 MB
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
class BSTIterator {
private:
    void push(TreeNode* root,stack<TreeNode*>& stk){
        while(root!=nullptr){
            stk.push(root);
            root = root->left;
        }
    }

public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        push(root,stk);
    }
    
    int next() {
        TreeNode* node = stk.top();stk.pop();
        push(node->right,stk);
        return node->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */