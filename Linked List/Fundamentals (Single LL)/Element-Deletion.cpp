#include<bits/stdc++.h>

/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* deleteNodeWithValueX(ListNode* &head, int X) {
        if(head == NULL){
            return NULL;
        }
        if(head -> val == X){
            ListNode* temp = head;
            head = head -> next;
            free(temp);
            return head;
        }
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            if(temp -> val == X){
                prev->next = prev->next->next;
                free(temp);
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        return head;
    }
};

"Time Complexity:O(n) because, in the worst case, it iterates through the entire linked list to find the node to delete.
Space Complexity:O(1) because it uses a constant amount of extra space, regardless of the size of the linked list."