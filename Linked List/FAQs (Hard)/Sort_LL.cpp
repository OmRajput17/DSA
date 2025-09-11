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

// Optimal using 2 pointers, merge Sort and DnC

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
    ListNode* findMiddle(ListNode* &head){

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeLL(ListNode* &l1, ListNode* &l2){
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(t1!=NULL && t2!=NULL){
            if(t1->val <= t2->val){
                temp->next = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }
        temp->next = t1 ? t1 : t2;

        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next==NULL){
            return head;
        }

        ListNode* middle = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;

        middle->next = nullptr;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return mergeLL(leftHead, rightHead);
    }
};

"Time Complexity:O(n log n) due to the recursive calls that split the list and the merge operation.
Space Complexity:O(log n) due to the recursive call stack."



// Brute Force using Extra space
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());
        temp = head;
        for(auto it:arr){
            temp->val = it;
            temp=temp->next;
        }
        return head;
    }
};

"Time Complexity:O(n log n) due to sorting the array of size n.
Space Complexity:O(n) due to storing linked list elements in an array."
