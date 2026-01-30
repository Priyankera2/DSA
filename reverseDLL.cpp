#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;Node* prev,*next;
    Node(int data1){
         data=data1;
         prev=nullptr;
         next=nullptr;
    }
    Node(int data1, Node* prev1, Node* next1){
        data=data1;
        prev=prev1;
        next=next1;
    }
};
Node* reverseList(Node* head){
    if(head==NULL||head->next==nullptr){
        return head;
    }
    Node* temp=head;
    Node* back=NULL;
    while(temp){
        back=temp->prev;
        temp->prev=temp->next;
        temp->next=back;
        temp=temp->prev;
    }
    return back->prev;
}
int main(){
    int arr[]={4,2,3,1};
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<4;i++){
            Node* newnode=new Node( arr[i],temp,nullptr);
            temp->next=newnode;
            temp=newnode;
    }
    temp=reverseList(head);
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}
