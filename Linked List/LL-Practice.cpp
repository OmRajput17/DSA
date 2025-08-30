#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1, Node* next1){
        data = data1; 
        next = next1;
    }

    public:
    Node(int data1){
        data = data1; 
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<< head->data << " ";
        head = head -> next;
    }
    cout<<endl;
}

Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head -> next;
    delete(temp);
    return head;
}

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    delete(temp -> next);
    temp -> next = nullptr;

    return head;
}

Node* deleteKthNode(Node* &head, int k) {
    if(head == NULL){
        return head;
    }
    if(k==1){
        head = head->next;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}
Node* deleteEl(Node* &head, int el) {
    if(head == NULL){
        return head;
    }
    if(head->data==el){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

Node* insertHead(Node* &head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

Node* insertTail(Node* &head, int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node* insertK(Node* &head, int k, int val){
    if(head == NULL){
        if(k==1){
            return new Node(val);
        }
    }
    if(k == 1){
        Node* temp = new Node(val, head);
        return temp;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            Node* X = new Node(val);
            X -> next = temp -> next;
            temp -> next = X;
            return head;
        }
        temp = temp -> next;
    }
    return head;
}

Node* insertBeforeValue(Node* &head, int k, int val){
    if(head == NULL){
        return NULL;
    }
    if(head->data == val){
        return new Node(k, head);
    }

    Node* temp = head;
    while(temp->next != NULL){

        if(temp->next->data == val){
            Node* X = new Node(k);
            X -> next = temp -> next;
            temp -> next = X;
            return head;
        }
        temp = temp -> next;
    }
    return head;
}

int main(){
    vector<int> arr = {22, 5, 8, 7};

    Node* head = convertArr2LL(arr);
    
    head = insertBeforeValue(head, 1, 22);
    print(head);
    // Node* y = new Node(arr[1], nullptr);
    // cout<< y->next;

    return 0;
}