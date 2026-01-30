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
Node* insertatend(Node*head,int data1){
    Node* temp=new Node(data1);
    if(head==nullptr)return temp;
    Node* move=head;
    while(move->next){
        move=move->next;
    }
    move->next=temp;
    temp->prev=move;
    return head;
}
Node* insertbeforetail(Node* head, int data){
    Node* temp=new Node(data);
    Node* move=head;
    if(head==nullptr)return temp;
    if(head->next==nullptr)return insertatbegin(head,data);
    while(move->next){
        move=move->next;
    }
    Node* back=move->prev;
    //if(back==nullptr)
   
    back->next=temp;
    move->prev=temp;
    return temp;

}
Node* insertatkth(Node* head, int k,int data){
    Node* temp=new Node(data);
    int cnt=0;
    Node* move=head;
    if(k==1)return insertatbegin(head,data);
    while(move){
        cnt++;
        if(cnt==k)break;
        move=move->next;
    }
    
    if(cnt<k||k<1)return head;
    
    //if(move==nullptr)return insertatend(head,data);
    Node* back=move->prev;
    back->next=temp;
    move->prev=temp;
    temp->next=move;
    temp->prev=back;
    return head;
}
void insertbeforenode(Node* node,int data){
    Node* newnode=new Node(data);
    
    Node* back=node->prev;
    
    back->next=newnode;
    node->prev=newnode;
    newnode->next=node;
    newnode->prev=back;

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
    Node* nodebegin=insertatkth(head,1,2);
    while(nodebegin){
        cout<<nodebegin->data<<" ";
        nodebegin=nodebegin->next;
    }
}