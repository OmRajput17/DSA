#include <bits/stdc++.h>
using namespace std;

/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution {
public:
    ListNode* insertBeforeTail(ListNode* head, int X) {
        if(head->next == NULL){
            ListNode* newHead = new ListNode(X, head, nullptr);
            head -> prev = newHead;
            return newHead; 
        }

        ListNode* tail = head;
        while(tail->next != NULL){
            tail = tail -> next;
        }

        ListNode* back = tail->prev;
        ListNode* newNode = new ListNode(X, tail, back);
        back -> next = newNode;
        tail -> prev = newNode;

        return head;
    }   
};

"Time Complexity: O(N) where N is the length of the array. We iterate through the input array exactly once and at each element perform constant time operations.
Space Complexity: O(1) as no extra space is used."