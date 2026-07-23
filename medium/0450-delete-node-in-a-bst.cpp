////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 450. Delete Node in a BST
// Difficulty : Medium
// Link       : https://leetcode.com/problems/delete-node-in-a-bst/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: in-order traversal with node replacement | Time: O(h) | Space: O(h))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 34.3 MB
// Date       : 2026-07-23
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
    bool isleaf(TreeNode* node){
        if(node->left == nullptr && node->right == nullptr)
            return true;
        else
            return false;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        TreeNode* prev = nullptr;

        while(curr != nullptr){
            if(curr->val == key)break;
            else if(curr->val > key){
                prev = curr;
                curr = curr->left;
            }
            else{
                prev = curr;
                curr = curr->right;
            }
        }
        if(curr == nullptr)return root;
        if(curr == root && isleaf(curr)) return nullptr;
        if(isleaf(curr) && curr!=root){
            if(prev->left == curr)prev->left = nullptr;
            else    prev->right = nullptr;
            return root;
        }
        else{
            TreeNode* p = curr;
            TreeNode* c;

            if(curr->left!=nullptr && curr->left->right == nullptr){
                curr->val = curr->left->val;
                curr->left = curr->left->left;
            }
            else if(curr->right!=nullptr &&curr->right->left == nullptr){
                curr->val = curr->right->val;
                curr->right = curr->right->right;
            }

            else if(p->left!=nullptr){
                c = p->left;
                while(c->right!=nullptr){
                    p = c;
                    c = c->right;
                }
                curr->val = c->val;
                p->right = c->left;
            }
            else{
                c = p->right;
                while(c->left!=nullptr){
                    p = c;
                    c = c->left;
                }
                curr->val = c->val;
                p->left = c->right;
            }
        }

        return root;
    }
};