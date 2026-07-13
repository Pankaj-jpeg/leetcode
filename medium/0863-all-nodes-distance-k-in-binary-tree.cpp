////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 863. All Nodes Distance K in Binary Tree
// Difficulty : Medium
// Link       : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Breadth-First Search (BFS) with parent mapping | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 16.5 MB
// Date       : 2026-07-13
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void trav(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& m,unordered_map<TreeNode*,bool>& vist){
        if(root == NULL)
            return;
        vist.insert({root,false});
        if(root->left!=NULL)m.insert({root->left,root});
        if(root->right!=NULL)m.insert({root->right,root});

        trav(root->left,m,vist);
        trav(root->right,m,vist);
        
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> par;
        unordered_map<TreeNode*,bool> vist;
        trav(root,par,vist);

        vector<int> res;

        queue<TreeNode*> q;

        q.push(target);

        int dist = 0;

        while(!q.empty()){
            int size = q.size();
            if(dist == k)
                break;
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                vist[node] = true;
                if(node->left!=NULL && !vist[node->left]){
                    q.push(node->left);
                }
                if(node->right!=NULL && !vist[node->right]){
                    q.push(node->right);
                }
                if(par[node]!=NULL && !vist[par[node]]){
                    q.push(par[node]);
                }
            }

            dist++;
        }

        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;

    }
};