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

// Optimal

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even != NULL && even->next!=NULL){
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};

"Time Complexity:O(n) because the while loop iterates through the linked list once.
Space Complexity:O(1) because it uses a constant amount of extra space, regardless of the input size."


// Brute Force

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL){
            return head;
        }

        vector<int> arr;
        ListNode* temp = head;
        while(temp!=NULL && temp->next != NULL){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp){
            arr.push_back(temp->val);
        }

        temp = head->next;
        while(temp!=NULL && temp->next != NULL){
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp){
            arr.push_back(temp->val);
        }

        int i = 0;
        temp = head;
        while(temp!=NULL){
            temp -> val = arr[i];
            i++;
            temp = temp->next; 
        }

        return head;
    }
};

"Time Complexity: O(2xN) for the following reasons:-
Traversing the odd-indexed elements takes O(N/2) time.
Traversing the even-indexed elements takes O(N/2) time.
Updating the linked list with the values from the array takes O(N) time.
Here N is the size of the linked list.

Space Complexity: O(N) because an additional list is used to store the grouped elements from the linked list."