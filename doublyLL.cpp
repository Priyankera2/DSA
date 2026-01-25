#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
    int data;
    Node* next,*prev;
    Node(int data1){
        this->data=data1;
        this->next=nullptr;
        this->prev=nullptr;
    }
    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
};
Node* deletehead(Node* head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    head->prev=nullptr;
    delete(temp);
    return head;
}
Node* deletetail(Node* head){
    if(head==nullptr||head->next==nullptr)return NULL;
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
}
     Node* tail=temp->next;
     temp->next=nullptr;
     tail->prev=nullptr;
     delete(tail);
     return head;
}
int main(){
     int  arr[]={1,2,3,4};
     Node* head=new Node(arr[0]);
     Node* prev=head;
     int n=sizeof(arr)/sizeof(arr[0]);
     for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
     }
     deletetail(head);
     while(head){
        cout<<head->data<<" ";
        head=head->next;
     }
}