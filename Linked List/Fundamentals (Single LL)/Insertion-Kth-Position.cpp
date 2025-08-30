#include<bits.stdc++.h>

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
    ListNode* insertAtKthPosition(ListNode* &head, int X, int k) {
        if(head == NULL){
            if(k==1){
                return new ListNode(X);
            }
        }
        if(k==1){
            ListNode* temp =  new ListNode(X, head);
            return temp;
        }
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            if(cnt == k-1){
                ListNode* newNode = new ListNode(X);
                newNode->next = temp-> next;
                temp->next = newNode;
                return head;
            }
            temp = temp->next;
        }

        return head;
    }
};