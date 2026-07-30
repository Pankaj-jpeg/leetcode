////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 207. Course Schedule
// Difficulty : Medium
// Link       : https://leetcode.com/problems/course-schedule/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Depth-First Search (DFS) with cycle detection | Time: O(n + m) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 4 ms  |  Memory: 19.6 MB
// Date       : 2026-07-30
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool dfs(vector<vector<int>>& adj,int i,vector<int>& pathVis,vector<int>& vis){
        if(pathVis[i])
            return true;
        if(vis[i])
            return false;
        
        vis[i] = 1;
        pathVis[i] = 1;

        bool found = false;
        for(auto it : adj[i]){
            found = found || dfs(adj,it,pathVis,vis);
            if(found){
                break;
            }
        } 

        pathVis[i] = 0;
        return found;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for(int i = 0;i<prerequisites.size();i++){
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            adj[v].push_back(u);
        }

        vector<int> pathVis(n,0);
        vector<int> vis(n,0);
       

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                if(dfs(adj,i,pathVis,vis))
                    return false;
            }
        }
        

        return true;
        
    }
};