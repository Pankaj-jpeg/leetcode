////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 743. Network Delay Time
// Difficulty : Medium
// Link       : https://leetcode.com/problems/network-delay-time/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Dijkstra's algorithm with priority queue | Time: O(n log n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 92 ms  |  Memory: 47.9 MB
// Date       : 2026-08-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    struct Node{
        int node;
        int time;
    };
    struct Comp{
        bool operator()(const Node& a,const Node& b){
            return a.time > b.time;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int t = it[2];

            adj[u].push_back({v,t});
        }

        priority_queue<Node,vector<Node>,Comp> q;
        vector<int> min_ti(n+1,INT_MAX);
        Node s(k,0);
        q.push(s);
        min_ti[k] = 0;
        while(!q.empty()){
            Node it = q.top();
            q.pop();

            if(min_ti[it.node] < it.time)continue;
            min_ti[it.node] = it.time;

            for(auto ne : adj[it.node]){
                if(min_ti[ne.first] > (it.time + ne.second)){
                    Node temp(ne.first,it.time + ne.second);
                    q.push(temp);
                    min_ti[ne.first] = it.time + ne.second;
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1;i<=n;i++){
            if(min_ti[i] == INT_MAX)
                return -1;
            ans = max(ans,min_ti[i]);
        }

        return ans;
        
    }
};