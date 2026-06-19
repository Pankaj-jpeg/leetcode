////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 148. Sort List
// Difficulty : Medium
// Link       : https://leetcode.com/problems/sort-list/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: merge sort with divide and conquer | Time: O(n log n) | Space: O(log n)
// Time       : 
// Space      : 
// Runtime    : 8 ms  |  Memory: 57.1 MB
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
    void merge(ListNode** head,ListNode** mid){
        ListNode* newHead=NULL;
        ListNode* itr1 = (*head);
        ListNode* itr2 = (*mid);
        ListNode* curr=NULL;
        ListNode* prev=NULL;
        while(itr1!=NULL && itr2!=NULL){
            if((itr1)->val <= (itr2)->val){
                curr = itr1;
                itr1 = itr1->next;
            }
            else{
                curr = itr2;
                itr2 = itr2->next;
            }
            if(newHead == NULL){
                newHead=curr;
                prev = curr;
            }
            else{
                prev->next = curr;
                prev = curr;
            }
        }

        while(itr1!=NULL){
            curr = itr1;
            itr1 = itr1->next;
            if(newHead == NULL){
                newHead=curr;
                prev = curr;
            }
            else{
                prev->next = curr;
                prev = curr;
            }
        }
        
        while(itr2!=NULL){
            curr = itr2;
            itr2 = itr2->next;
            if(newHead == NULL){
                newHead=curr;
                prev = curr;
            }
            else{
                prev->next = curr;
                prev = curr;
            }
        }
        *head = newHead;
    }
    void mergeSort(ListNode** head,ListNode** tail){
        if(*head == NULL || (*head)->next == NULL)
            return;
        ListNode* slow = *head;
        ListNode* fast = (*head)->next;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* itr = slow->next;
        slow->next = NULL;
        mergeSort(head, &slow);
        mergeSort(&(itr),tail);
        merge(head,&itr);
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* tail = head;
        while(tail->next!=NULL){
            tail = tail->next;
        }
        mergeSort(&head,&tail);
        return head;
    }
};