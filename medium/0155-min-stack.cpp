////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 155. Min Stack
// Difficulty : Medium
// Link       : https://leetcode.com/problems/min-stack/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: maintaining a stack with both value and min value pairs | Time: O(1) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 60 ms  |  Memory: 152.5 MB
// Date       : 2026-07-20
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MinStack {
public:
    vector<pair<int,int>> stk;
    MinStack() {
        
    }
    
    void push(int value) {
        int Min = getMin();
        if(stk.empty() || Min > value)Min = value;
        stk.push_back({value,Min});  
    }
    
    void pop() {
        if(stk.empty())return;
        stk.pop_back();
    }
    
    int top() {
        if(stk.empty())return -1;
        return stk.back().first;
    }
    
    int getMin() {
        if(stk.empty())return -1;
        return stk.back().second;
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