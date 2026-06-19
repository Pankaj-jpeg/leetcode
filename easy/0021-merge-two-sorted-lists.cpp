////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 21. Merge Two Sorted Lists
// Difficulty : Easy
// Link       : https://leetcode.com/problems/merge-two-sorted-lists/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: iterative, two-pointer technique | Time: O(n + m) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 19.5 MB
// Date       : 2026-01-10
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=nullptr;
        ListNode* prev=nullptr;
        ListNode* current=nullptr;

        while(list1!=nullptr && list2!=nullptr){

            if(list1->val <= list2->val ){
                  current = list1;
                  list1=list1->next; 
            }
            else{
                current = list2;
                list2=list2->next;
            }

            if(head==nullptr){
                head = current;
                prev = current;
            }
            else{
                prev->next = current;
                prev = current;
            }
    
    }
    if(list1!=nullptr){
        if(head==nullptr){
            head = list1;
        }
        else{
                prev->next = list1;
            }
    }
    if(list2!=nullptr){
        if(head==nullptr){
            head = list2;
        }
        else{
                prev->next = list2;
            }
    }
    return head;
}
};