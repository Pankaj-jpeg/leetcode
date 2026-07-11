////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 987. Vertical Order Traversal of a Binary Tree
// Difficulty : Hard
// Link       : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: depth-first search with in-order traversal | Time: O(n log n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 2 ms  |  Memory: 15.2 MB
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
    void trav(TreeNode* root,vector<tuple<int,int,int>>& nodes,int row,int col){
        if(root == nullptr)
            return;        

        nodes.push_back({col,row,root->val});
        trav(root->left,nodes,row+1,col-1);
        trav(root->right,nodes,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        vector<tuple<int,int,int>> nodes;
        trav(root,nodes,0,0);


        sort(nodes.begin(),nodes.end());
        
        res.push_back({get<2>(nodes[0])});
        int idx = 0;
        for(int i = 1;i<nodes.size();i++){
            if(get<0>(nodes[i]) != get<0>(nodes[i-1])){
                res.push_back({});
                idx++;
                res[idx].push_back(get<2>(nodes[i]));
            }
            else{
                res[idx].push_back(get<2>(nodes[i]));
            }
        }
        return res;
    }
};