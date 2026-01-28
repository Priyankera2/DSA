#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data1){
        data=data1;
        prev=NULL;
        next=NULL;
    }
    Node(int data1,Node* next1, Node* prev1){
        data=data1;
        prev=prev1;
        next=next1;
    }
};
Node* insertatbegin(Node* head, int data1){
    
    Node* temp=new Node(data1);
    if(head==nullptr)return temp;
    temp->next=head;
    head->prev=temp;
    return temp;
}

int main(){
    int arr[]={1,2,3,4,5,6};
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<6;i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;

    }
    Node* nodebegin=insertatend(head,7);
    while(nodebegin){
        cout<<nodebegin->data<<" ";
        nodebegin=nodebegin->next;
    }
}