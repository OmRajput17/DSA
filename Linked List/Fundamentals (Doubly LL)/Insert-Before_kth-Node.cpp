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
    ListNode* insertBeforeKthPosition(ListNode* head, int X, int k) {
        if(k==1){
            ListNode* newHead = new ListNode(X, head, nullptr);
            head -> prev = newHead;
            return newHead;
        }

        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            if(cnt == k){
                break;
            }
            temp = temp -> next;
        }
        ListNode* back = temp -> prev;
        ListNode* newNode = new ListNode(X, temp, back);
        back -> next = newNode;
        temp -> prev = newNode;
        return head;
    }
};

"Time Complexity: O(N), where N is the number of nodes in the Linked List. In the worst case, it involves traversing N nodes in the Doubly Linked List to reach the last element. In the best case, when K is 0 (insertion at the head), the time complexity is O(1) as it involves a constant number of operations. In the average case, it's O(K).
Space Complexity: O(1) as no extra space is used."