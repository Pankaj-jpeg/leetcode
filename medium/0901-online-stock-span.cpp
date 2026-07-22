////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 901. Online Stock Span
// Difficulty : Medium
// Link       : https://leetcode.com/problems/online-stock-span/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: stack-based, maintaining a decreasing price sequence | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 25 ms  |  Memory: 91.9 MB
// Date       : 2026-07-22
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class StockSpanner {
public:
    stack<pair<int,int>> stk;
    StockSpanner() {
    }
    
    int next(int price) {
        int cnt = 1;
        while(!stk.empty() && stk.top().first <= price){
            cnt+=(stk.top().second);
            stk.pop();
        }
        stk.push({price,cnt});
        return cnt;
    }

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */