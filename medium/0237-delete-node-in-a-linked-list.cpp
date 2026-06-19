////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 237. Delete Node in a Linked List
// Difficulty : Medium
// Link       : https://leetcode.com/problems/delete-node-in-a-linked-list/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: in-place replacement | Time: O(1) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 5 ms  |  Memory: 12.4 MB
// Date       : 2026-06-15
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};