////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 802. Find Eventual Safe States
// Difficulty : Medium
// Link       : https://leetcode.com/problems/find-eventual-safe-states/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: depth-first search (DFS) with topological sorting | Time: O(n + m) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 51.6 MB
// Date       : 2026-08-07
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& vis,int i,vector<int>& res){
        vis[i] = 1;

        for(auto ne : graph[i]){
            if(vis[ne] == 0 && !dfs(graph,vis,ne,res)){
                return false;
            }
            else if(vis[ne] == 1)
                return false;
        }
        vis[i] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n,0);
        vector<int> res;
        for(int i = 0;i<n;i++){
            if(vis[i] == 0){
                dfs(graph,vis,i,res);
            }
        }
        for(int i = 0;i<n;i++){
            if(vis[i] == 2)
                res.push_back(i);
        }
        return res;
    }
};