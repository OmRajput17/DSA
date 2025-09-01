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
    ListNode* insertBeforeHead(ListNode* head, int X) {
        ListNode* newHead = new ListNode(X, head, nullptr);
        head->prev = newHead;

        return newHead;    
    }
};

"Time Complexity: O(1) because only a constant number of pointer updates are being performed regardless of the size of the Doubly Linked List.
Space Complexity: O(1) as no extra space is used."
