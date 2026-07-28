////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 547. Number of Provinces
// Difficulty : Medium
// Link       : https://leetcode.com/problems/number-of-provinces/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: depth-first search (DFS) | Time: O(n + m) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 19.3 MB
// Date       : 2026-07-28
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<int>& vis,int node){
        vis[node] = 1;

        for(int i = 0;i<isConnected.size();i++){
            if(isConnected[node][i] && !vis[i]){
                dfs(isConnected,vis,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        int cnt = 0;
        vector<int> vis(n,0);

        for(int i = 0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(isConnected,vis,i);
            }
        }


        return cnt;
    }
};