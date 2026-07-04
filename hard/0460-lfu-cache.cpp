////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 460. LFU Cache
// Difficulty : Hard
// Link       : https://leetcode.com/problems/lfu-cache/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: frequency-based cache eviction | Time: O(1) | Space: O(n))
// Time       : 
// Space      : 
// Runtime    : 113 ms  |  Memory: 186.8 MB
// Date       : 2026-07-04
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class LFUCache {
public:
    int max;
    int min_f;
    unordered_map<int,list<int>> m1;
    unordered_map<int,pair<pair<std::list<int> :: iterator,int>,int>> m2;
    LFUCache(int capacity) {
        max = capacity;
        min_f=1;
    }
    
    int get(int key) {
        if(m2.find(key) == m2.end())
            return -1;
        
        int freq = m2.find(key)->second.first.second;
        auto it = m2.find(key)->second.first.first;

        m1[freq+1].splice(m1[freq+1].begin(),m1[freq],it);

        m2.find(key)->second.first.second++;

        if(m1[min_f].size() == 0)
            min_f++;

        return m2.find(key)->second.second;
    }
    
    void put(int key, int value) {
        if(m2.find(key) == m2.end() && m2.size() < max){
            m1[1].push_front(key);
            m2.insert({key,{{m1[1].begin(),1},value}});
            min_f = 1;
        }
        else if(m2.find(key)!=m2.end()){
            get(key);
            m2.find(key)->second.second = value;
        }
        else{
            int eject = m1[min_f].back();
            m1[min_f].pop_back();
            m2.erase(eject);
            m1[1].push_front(key);
            m2.insert({key,{{m1[1].begin(),1},value}});
            min_f = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */