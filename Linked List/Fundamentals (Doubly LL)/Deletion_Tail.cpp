#include<bits/stdc++.h>
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
    ListNode* deleteTail(ListNode* head) {
        if(head == NULL || head->next == NULL){
        return NULL;
    }
    ListNode* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    ListNode* prev = tail->prev;
    prev -> next = nullptr;
    tail -> prev = nullptr;
    delete tail;

    return head;
    }
};

"Time Complexity: O(N), where N is the number of nodes in the DLL.
This is because we traverse the entire DLL to reach the end to delete the tail.

Space Complexity: O(1) as no extra space used."