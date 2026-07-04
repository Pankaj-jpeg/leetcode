////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 901. Online Stock Span
// Difficulty : Medium
// Link       : https://leetcode.com/problems/online-stock-span/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Time       : 
// Space      : 
// Runtime    : 15 ms  |  Memory: 92 MB
// Date       : 2026-07-03
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class StockSpanner {
public:
    stack<pair<int,int>> stk;
    StockSpanner() {
    }
    
    int next(int price) {
        int cnt = 0;
        while(!stk.empty() && stk.top().first <= price){
            cnt+=stk.top().second;
            stk.pop();
            cnt++;
        }

        stk.push({price,cnt});

        return cnt+1;
    }

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */