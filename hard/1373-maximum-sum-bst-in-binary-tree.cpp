////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1373. Maximum Sum BST in Binary Tree
// Difficulty : Hard
// Link       : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Depth-first search with recursive traversal | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 7 ms  |  Memory: 104.7 MB
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
private:
    struct Node{
        int minNode;
        int maxNode;
        int sum;
        Node(int x,int y,int z){
            minNode = x;
            maxNode = y;
            sum = z;
        }
    };
public:
    
    Node trav(TreeNode* root,int& maxSum){
        if(root == nullptr){
            return Node(INT_MAX,INT_MIN,0);
        }

        Node left = trav(root->left,maxSum);
        Node right = trav(root->right,maxSum);

        if(left.maxNode < root->val && root->val < right.minNode){
            int sum = left.sum + root->val + right.sum;
            maxSum = max(maxSum,sum);
            return Node(min(left.minNode,root->val),max(root->val,right.maxNode),sum);
        }

        return Node(INT_MIN,INT_MAX,0);

    }
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        trav(root,maxSum);

        return maxSum;
    }
};