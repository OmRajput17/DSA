#include<bits/stdc++.h>
using namespace std;

/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
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
private:
    ListNode *reverseList(ListNode *head){
        ListNode* temp = head;
        ListNode* back = nullptr;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = back;
            back = temp;
            temp = front;
        }

        return back;
    }
public:
    ListNode *addOne(ListNode *head) {
        int carry = 1;
        head = reverseList(head);
        ListNode* temp = head;

        while(temp!=NULL){

            // Handling Carry
            int sum = temp -> val + carry;
            carry = sum/10;
            temp -> val = sum % 10;

            // Early Exit if there is no carry 
            if(carry == 0){
                break;
            } 

            // Create new node if carry is left and there is no node left
            if(temp->next == NULL && carry != 0){
                temp -> next = new ListNode(carry);
                break;
            }

            temp = temp->next;
        }

        // Again reverse the list
        head = reverseList(head);
        return head;
    }
};


"Time Complexity:O(n) due to reversing the list and iterating through it once.
Space Complexity:O(1) because it uses a constant amount of extra space, excluding the space used by the linked list itself."