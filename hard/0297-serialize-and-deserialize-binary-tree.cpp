////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 297. Serialize and Deserialize Binary Tree
// Difficulty : Hard
// Link       : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: level order traversal with queue | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 23 ms  |  Memory: 32.3 MB
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
class Codec {
public:

    // Encodes a tree to a single string.

    string serialize(TreeNode* root) {
        string s = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();q.pop();
                if(node == nullptr)
                    s+="#,";
                else{
                    s+=(to_string(node->val)+",");
                    q.push(node->left);
                    q.push(node->right);
                }
            }      
        }
        
        return s;
    }


  
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        queue<TreeNode*> q;
        if(data[i] == '#')
            return nullptr;
        int num = 0;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();q.pop();
            getline(s,str,',');

            if(str == "#")
                node->left = NULL;
            else{
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            getline(s,str,',');

            if(str == "#")
                node->right = NULL;
            else{
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }

        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));