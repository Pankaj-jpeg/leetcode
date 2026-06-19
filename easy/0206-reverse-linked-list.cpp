////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 206. Reverse Linked List
// Difficulty : Easy
// Link       : https://leetcode.com/problems/reverse-linked-list/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: recursive backtracking | Time: O(n) | Space: O(n)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 13.4 MB
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
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
        

        ListNode* newHead = reverseList(head->next);

        ListNode* front = head->next;

        front->next = head;

        head->next = NULL;

        return newHead;
        
    }
};