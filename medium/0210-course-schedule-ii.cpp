////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 210. Course Schedule II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/course-schedule-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: topological sorting using DFS | Time: O(n + m) | Space: O(n + m))
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 19.4 MB
// Date       : 2026-08-06
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool dfs(vector<vector<int>>& adj,vector<int>& vis,vector<int>& rec,int i,vector<int>& res){
        vis[i] = 1;
        rec[i] = 1;

        for(auto neigh : adj[i]){
            if(!vis[neigh]){
                if(!dfs(adj,vis,rec,neigh,res))
                    return false;
            }
            else if(rec[neigh])
                return false;
           
        }
        res.push_back(i);
        rec[i] = 0;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto vec : prerequisites){
            int u = vec[0];
            int v = vec[1];
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);
        vector<int> res;
        vector<int> rec(n,0);
        
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                if(!dfs(adj,vis,rec,i,res))
                    return {};
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};