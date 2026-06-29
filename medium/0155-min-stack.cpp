////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 155. Min Stack
// Difficulty : Medium
// Link       : https://leetcode.com/problems/min-stack/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: maintaining a stack with both value and min value | Time: O(1) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 46 ms  |  Memory: 152.4 MB
// Date       : 2026-06-29
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MinStack {
public:
    vector<pair<int,int>> stk;
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
        return stk.empty() ? -1 : stk.back().first;
    }
    
    int getMin() {
        return stk.empty() ? -1 : stk.back().second;
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