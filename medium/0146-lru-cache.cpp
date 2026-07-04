////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 146. LRU Cache
// Difficulty : Medium
// Link       : https://leetcode.com/problems/lru-cache/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: combination of linked list and unordered map for LRU cache | Time: O(1) | Space: O(capacity))
// Time       : 
// Space      : 
// Runtime    : 47 ms  |  Memory: 173.2 MB
// Date       : 2026-07-04
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class LRUCache {
public:
    int max;
    list<int> q;
    unordered_map<int,pair<std::list<int> :: iterator,int>> m;
    LRUCache(int capacity) {
        max = capacity;    
    }
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        
        q.splice(q.begin(),q,m.find(key)->second.first);

        return m.find(key)->second.second;

    }
    
    void put(int key, int value) {
        if(m.find(key) == m.end() && m.size() < max){
            q.push_front(key);
            auto it = q.begin();
            m.insert({key,{it,value}});
        }
        else if(m.find(key) != m.end()){
            get(key);
            m.find(key)->second.second = value;
        }
        else{
            int eject = q.back();
            q.pop_back();
            m.erase(eject);
            q.push_front(key);
            auto it = q.begin();
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