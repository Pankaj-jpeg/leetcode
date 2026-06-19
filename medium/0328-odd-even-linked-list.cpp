////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 328. Odd Even Linked List
// Difficulty : Medium
// Link       : https://leetcode.com/problems/odd-even-linked-list/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique, alternating between odd and even nodes | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 15.7 MB
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
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* evenHead = head->next;
        ListNode* oddHead = head;

        ListNode* evenItr = evenHead;
        ListNode* oddItr = oddHead;

        while(oddItr->next!=NULL && evenItr->next!=NULL){
            oddItr->next = oddItr->next->next;
            evenItr->next = evenItr->next->next;

            oddItr = oddItr->next;
            evenItr = evenItr->next;
        }
        oddItr->next = evenHead;

        return oddHead;
    }
};