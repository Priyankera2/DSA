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
Node* deletekthNode(Node* head,int k){
    int cnt=0;
    
    Node* temp=head;
    while(temp){
        cnt++;
        if(cnt==k)break;temp=temp->next;
    }
    if(k>cnt||k<1)return head;
    Node* back=temp->prev;
    Node* front=temp->next;

    if(back==nullptr&&front==nullptr){                 // edge case1: single element case , then prev and next will be null
        delete(head);
        return NULL;}

    else if(back==NULL){                              // edge case2: k=1 , then temp is head and prev of head is null;
        front->prev=nullptr;
        delete(temp);
        return front;
    }
    else if(front==nullptr){                           // edge case3: kth node is tail, then front will be null;
        back->next=nullptr;
        delete(temp);
        return head;
    }
    back->next=front;                                 // middle node deletion
    front->prev=back;
    temp->prev=nullptr;
    temp->next=nullptr;
    delete(temp);
    return head;
    
}
Node* deleteNodeValue(Node* head, int node){
    Node* temp =head;
   
    while(temp&&temp->data!=node){
        temp=temp->next;
    }
    if(!temp)return head;
    Node* back=temp->prev;
    Node* front=temp->next;
    if(front==nullptr){
        back->next=nullptr;
        temp->prev=nullptr;
        delete(temp);
        return head;

    }
    front->prev=back;
    back->next=front;
    temp->prev=nullptr;
    temp->next=nullptr;
    delete(temp);
    return head;

}
void deleteNode(Node* node){
    Node* back=node->prev,*front=node->next;
    if(front==nullptr){
        back->next=nullptr;
        node->prev=nullptr;
        delete(node);

    }
   
    else{
    back->next=front;
    front->prev=back;
    node->next=nullptr;
    node->prev=nullptr;
    delete(node);}
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
     Node* temp=head;
     deleteNode(head->next->next);
     
     while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
     }
}