////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 142. Linked List Cycle II
// Difficulty : Medium
// Link       : https://leetcode.com/problems/linked-list-cycle-ii/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: Floyd's Tortoise and Hare algorithm (slow and fast pointers) | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 3 ms  |  Memory: 11.2 MB
// Date       : 2026-07-16
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        if(head == nullptr || head->next == nullptr)
            return nullptr;

        while(slow!=nullptr && fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(slow != fast)
            return nullptr;
        
        ListNode* res = head;
        while(res!=slow){
            res = res->next;
            slow = slow->next;
        }
        return res;
    }
};