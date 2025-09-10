#include <bits/stdc++.h>
using namespace std;

/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

// Optimal Approach without using Extra space
/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
private:
    ListNode* mergeList(ListNode* &l1, ListNode* &l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;

        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                res->child = l1;
                res = l1;
                l1 = l1->child;
            }
            else{
                res->child = l2;
                res = l2;
                l2 = l2->child;
            }
            res->next = nullptr;
        }

        if(l1){
            res->child = l1;
        }
        else{
            res->child = l2;
        }

        return dummy->child;
    }
public:
    ListNode* flattenLinkedList(ListNode* &head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* mergedHead = flattenLinkedList(head->next);

        return mergeList(head, mergedHead);
    }
};


// Brute Force using Extra Space and extra LL
class Solution {
private:
    ListNode* convertArrToLinkedList(vector<int> &arr){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        for(int i = 0; i<arr.size(); i++){
            temp->child = new ListNode(arr[i]);
            temp = temp->child;
        }

        return dummy->child;
    }
public:
    ListNode* flattenLinkedList(ListNode* &head) {
        ListNode* temp = head;
        ListNode* tempChild;
        vector<int> arr;
        while(temp != NULL){
            tempChild = temp;
            while(tempChild != NULL){
                arr.push_back(tempChild->val);
                tempChild = tempChild->child;
            }
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        return convertArrToLinkedList(arr);
    }
};

"Time Complexity:O(n*m + klogk), where n is the length of the main list, m is the maximum length of a child list, and k is the total number of nodes in all lists which is sorted.
Space Complexity:O(k), where k is the total number of nodes in all lists, due to the array used to store node values."