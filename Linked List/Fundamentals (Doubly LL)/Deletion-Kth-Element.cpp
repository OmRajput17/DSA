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
private:
    ListNode* deleteHead(ListNode* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    ListNode* temp = head;

    head = head->next;
    head -> prev = nullptr;
    temp -> next = nullptr;
    delete (temp);

    return head;
}

ListNode* deleteTail(ListNode* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    ListNode* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    ListNode* back = tail->prev;
    back -> next = nullptr;
    tail -> prev = nullptr;
    delete tail;

    return head;
}
public:
    ListNode* deleteKthElement(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }

        ListNode* KNode = head;
        int cnt = 0;
        while(KNode != NULL){
            cnt++;
            if(cnt == k){
                break;
            }

            KNode = KNode -> next;
        }

        ListNode* back = KNode -> prev;
        ListNode* front = KNode -> next;

        if(back == NULL && front == NULL){
            // Case1 : Single Node
            return NULL;
        }
        else if(back == NULL){
            // Case2 : Head Node
            return deleteHead(head);
        }
        else if(front == NULL){
            // Case3 : Tail
            return deleteTail(head);
        }
        // Node in the middle
        back -> next = front;
        front -> prev = back;

        KNode->next = nullptr;
        KNode->prev = nullptr;

        delete KNode;

        return head;
    }
};

"Time Complexity: O(k) because it only involves identifying the Kth node and updating its references to delete it.
Space Complexity: O(1) as no extra space is used."