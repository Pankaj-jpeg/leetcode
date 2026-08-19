////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// Difficulty : Medium
// Link       : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 14 ms  |  Memory: 17.4 MB
// Date       : 2026-08-18
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n,vector<int>(n,INT_MAX));

        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            cost[u][v] = w;
            cost[v][u] = w;
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == j)
                    cost[i][j] = 0;
            }
        }


        for(int via = 0;via<n;via++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(cost[i][via] == INT_MAX || cost[via][j] == INT_MAX)continue;
                    cost[i][j] = min(cost[i][j],cost[i][via] + cost[via][j]);
                }
            }
        }

        int city = -1;
        int Min_cnt = INT_MAX;
        for(int i = 0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j<n;j++){
                if(cost[i][j] <= distanceThreshold)
                    cnt++;
            }

            if(cnt <= Min_cnt){
                Min_cnt = cnt;
                city = i;
            }
        }

        return city;
    }
};