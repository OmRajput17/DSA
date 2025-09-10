#include<bits/stdc++.h>
using namespace std;

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
// Optimal using two pointer and one of the LL
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        while(t1 != nullptr && t2 != nullptr){
            if(t1->val <= t2->val){
                temp->next = t1;
                t1 = t1->next;
            }
            else{
                temp->next = t2;
                t2 = t2->next;
            }
            temp=temp->next;
        }

        if(t1 != NULL){
            temp->next = t1;
        }
        else{
            temp->next = t2;
        }

        return dummy->next;
    }
};

"Time Complexity:O(m+n) where m and n are lengths of the two linked lists
Space Complexity:O(1) because we are using constant extra space"

// Brute Force using extra array and sorting the array
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        while(t1 != NULL){
            arr.push_back(t1->val);
            t1 = t1->next;
        }
        while(t2 != NULL){
            arr.push_back(t2->val);
            t2 = t2->next;
        }
        sort(arr.begin(), arr.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        for(int i = 0; i<arr.size(); i++){
            ListNode* newNode = new ListNode(arr[i]);
            temp->next = newNode;
            temp = temp->next;
        }
        return dummy->next;
    }
};

"Time Complexity:O(n + m + (n+m)log(n+m)), where n and m are the lengths of the two lists.
Space Complexity:O(n + m), where n and m are the lengths of the two lists."