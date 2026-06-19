////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 61. Rotate List
// Difficulty : Medium
// Link       : https://leetcode.com/problems/rotate-list/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: two-pointer technique with linked list reversal | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 16.5 MB
// Date       : 2026-06-16
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
    ListNode* reverse(ListNode** list){
        ListNode* prev = NULL;
        ListNode* curr = *list;
        ListNode* next = curr;

        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* fast = head;
        int len = 0;
        ListNode* itr=head;
        while(itr!=NULL){
            len++;
            itr=itr->next;
        }
        if(head == NULL || head->next == NULL){
            return head;
        }
        k = k%len;
        while(k>0){
            fast = fast->next;
            k--;
        }
        ListNode* slow = head;
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* h1 = head;ListNode* newh1;
        ListNode* h2 = slow->next;ListNode* newh2;
        slow->next = NULL;
        newh1 = reverse(&h1);
        newh2 = reverse(&h2);

        h1->next = newh2;

        return reverse(&newh1);
    }
};