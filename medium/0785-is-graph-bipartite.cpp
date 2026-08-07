////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 785. Is Graph Bipartite?
// Difficulty : Medium
// Link       : https://leetcode.com/problems/is-graph-bipartite/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Depth-First Search (DFS) with color assignment | Time: O(n + m) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 17.4 MB
// Date       : 2026-08-06
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& vis,vector<int>& color,int i){
        vis[i] = 1;
        int col = color[i];
        for(auto neigh : graph[i]){
            if(!vis[neigh]){
                color[neigh] = !col;
                if(!dfs(graph,vis,color,neigh))
                    return false;
            }
            else{
                if(color[neigh] == col)
                    return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> color(n,-1);

        queue<int> q;
        
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                color[i] = 0;
                if(!dfs(graph,vis,color,i))
                    return false;
            }
        }
        return true;
    }
};