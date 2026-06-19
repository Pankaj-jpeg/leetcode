////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 876. Middle of the Linked List
// Difficulty : Easy
// Link       : https://leetcode.com/problems/middle-of-the-linked-list/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pass, first pass to find length, second pass to find middle | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 10 MB
// Date       : 2026-06-15
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
    ListNode* middleNode(ListNode* head) {
        int len=0;ListNode* itr = head;
        while(itr!=NULL){
            len++;
            itr = itr->next;
        }
        len = len/2 + 1;
        itr = head;
        while(len>1){
            len--;
            itr = itr->next;
        }
        return itr;
    }
};