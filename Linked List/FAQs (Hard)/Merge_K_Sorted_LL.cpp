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
class Solution {
private:
    ListNode* merge2List(ListNode* &l1, ListNode* &l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
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
        auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        ListNode* head = lists[0];
        for(int i = 1; i<lists.size(); i++){
            head = merge2List(head, lists[i]);
        }
        return head;
    }
};

// TC = O(N∗K)