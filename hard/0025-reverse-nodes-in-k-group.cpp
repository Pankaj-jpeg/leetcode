////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 25. Reverse Nodes in k-Group
// Difficulty : Hard
// Link       : https://leetcode.com/problems/reverse-nodes-in-k-group/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Approach: reversing linked list in k-sized chunks | Time: O(n) | Space: O(1)
// Time       : 
// Space      : 
// Runtime    : 0 ms  |  Memory: 16.4 MB
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* itr=head;
        while(itr!=NULL){
            len++;
            itr=itr->next;
        }
        itr = head;
        int rem = len%k;
        len = len-rem;
        int cnt = 0;
        ListNode* prevHead;
        ListNode* currHead = itr;
        ListNode* prev;
        while(len>0){
            if(cnt<k){
                if(cnt==k-1){
                    ListNode* temp = itr;
                    itr = temp->next;
                    temp->next = NULL;
                }
                else
                    itr = itr->next;
            }
            else if(cnt%k == 0){
                prevHead = currHead;
                currHead = itr;
                prev = currHead;
                itr = itr->next;
                currHead->next = prevHead;
            }
            else{
                ListNode* temp = itr;
                itr = itr->next;
                temp->next=prevHead;
                prev->next = temp;
                prev = temp;
            }
            cnt++;
            len--;
        }
    
        ListNode* p=NULL;
        ListNode* c=currHead;
        ListNode* n=c;

        while(c!=NULL){
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }


        currHead->next = itr;

        return p;
    }
};