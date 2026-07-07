////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 23. Merge k Sorted Lists
// Difficulty : Hard
// Link       : https://leetcode.com/problems/merge-k-sorted-lists/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: priority queue with min heap | Time: O(N log k) | Space: O(k)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 18.5 MB
// Date       : 2026-07-07
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct Comp{
        bool operator()(const pair<int,ListNode*>& a, const pair<int,ListNode*>& b){
            return a.first > b.first;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,Comp> h;
        for(int i = 0;i<lists.size();i++){
            if(lists[i]!=NULL){
                int num = lists[i]->val;
                h.push({num,lists[i]});
            }
        }

        ListNode* head=NULL;
        ListNode* prev=NULL;
        while(!h.empty()){
            ListNode* curr = h.top().second;
            ListNode* next = h.top().second->next;
            h.pop();
            if(next!=NULL){
                h.push({next->val,next});
            }
            if(head == NULL){
                head = curr;
                prev = curr;
            }
            else{
                prev->next = curr;
                prev = curr;
            }
        }

        return head;
    }
};