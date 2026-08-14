////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 1976. Number of Ways to Arrive at Destination
// Difficulty : Medium
// Link       : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Dijkstra's algorithm with priority queue | Time: O(E log E) | Space: O(E + V))
// Time       : 
// Space      : 
// Runtime    : 16 ms  |  Memory: 40.6 MB
// Date       : 2026-08-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    struct Node{
        long long node;
        long long time;
    };
    struct Comp{
        bool operator()(const Node& a,const Node& b){
            return a.time > b.time;
        }
    };
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<Node,vector<Node>,Comp> q;

        vector<pair<long long,long long>> min_t_paths(n,{LONG_MAX,0});
        min_t_paths[0] = {0,1};
        Node s(0,0);
        q.push(s);
        //vector<int> vis(n,0);

        while(!q.empty()){
            Node it = q.top();
            q.pop();
            //if(vis[it.node])continue;
            //vis[it.node] = 1;
            
            for(auto ne : adj[it.node]){
                if(min_t_paths[ne.first].first > ne.second + it.time){
                    q.push({ne.first,it.time + ne.second});
                    min_t_paths[ne.first].first = ne.second + it.time;
                    min_t_paths[ne.first].second = min_t_paths[it.node].second;
                }
                else if(min_t_paths[ne.first].first == ne.second + it.time){
                    min_t_paths[ne.first].second = (min_t_paths[ne.first].second + min_t_paths[it.node].second)%1000000007;
                }
            }
        }


        return min_t_paths[n-1].second;
    }
};