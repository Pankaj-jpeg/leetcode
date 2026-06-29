////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 155. Min Stack
// Difficulty : Medium
// Link       : https://leetcode.com/problems/min-stack/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer stack with min tracking | Time: O(1) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 78 ms  |  Memory: 166.5 MB
// Date       : 2026-06-28
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MinStack {
public:
    vector<vector<int>> stk;
    MinStack() {
    }
    
    void push(int value) {
        int min = getMin();
        if(stk.empty() || min > value) min = value;
        stk.push_back({value,min});
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.empty() ? -1 : stk.back()[0];
    }
    
    int getMin() {
        return stk.empty() ? -1 : stk.back()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */