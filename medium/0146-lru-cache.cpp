////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 146. LRU Cache
// Difficulty : Medium
// Link       : https://leetcode.com/problems/lru-cache/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: LRU Cache implementation using a combination of a doubly linked list (list) and an unordered map (unordered_map) | Time: O(1) | Space: O(capacity))
// Time       : 
// Space      : 
// Runtime    : 115 ms  |  Memory: 182.1 MB
// Date       : 2026-07-22
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class LRUCache {
public:
    list<int> l;
    unordered_map<int,pair<std::list<int>::iterator,int>> m;
    int max;
    LRUCache(int capacity) {
        max = capacity;
    }
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        
        auto it = m.find(key)->second.first;
        l.erase(it);
        l.push_front(key);
        m.find(key)->second.first = l.begin();
        return m.find(key)->second.second;
    }
    void put(int key, int value) {
        if(m.find(key) == m.end() && m.size() == max)
        {
            int temp = l.back();
            m.erase(temp);
            l.pop_back();
            l.push_front(key);
            auto it = l.begin();
            m.insert({key,{it,value}});
        }
        else if (m.find(key) != m.end()){
            m.find(key)->second.second = value;
            get(key);
        }
        else{
            l.push_front(key);
            auto it = l.begin();
            m.insert({key,{it,value}});
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */