////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 787. Cheapest Flights Within K Stops
// Difficulty : Medium
// Link       : https://leetcode.com/problems/cheapest-flights-within-k-stops/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Dijkstra's algorithm with priority queue | Time: O(n * m * log(n)) | Space: O(n + m))
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 19 MB
// Date       : 2026-08-14
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
struct Node{
    int node;
    int cost;
    int stops;
    Node(int node, int cost, int stops) : node(node), cost(cost), stops(stops) {}
};
struct Comp{
    bool operator()(const Node& a,const Node& b){
        return a.cost > b.cost;
    }
};
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto vec : flights){
            int x = vec[0];
            int y = vec[1];
            int price = vec[2];

            adj[x].push_back({price,y});
        }

        priority_queue<Node,vector<Node>,Comp> q;
        vector<int> min_stops(n,INT_MAX);
        Node s(src,0,0);
        q.push(s);
        while(!q.empty()){
            Node it = q.top();
            q.pop();

            if(min_stops[it.node] < it.stops) continue;
            min_stops[it.node] = it.stops;
            if(it.stops > k+1)
                continue;
            if(it.node == dst)
                return it.cost;
            
            for(auto ne : adj[it.node]){
                int x = ne.second;
                int p = ne.first;
                Node temp(x,it.cost+p,it.stops+1);
                q.push(temp);
            }
        }
        return -1;
    }
};