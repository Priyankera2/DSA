#include<bits/stdc++.h>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node(int data){
       this->data=data;
        this->next=nullptr;
    }
};

Node* convertLL(vector<int>arr){
    Node* head=new Node(arr[0]);
Node* temp=head;
for(int i=1;i<arr.size();i++){
    Node* newnode=new Node(arr[i]);
    temp->next=newnode;
    temp=temp->next;
}
return head;
}



Node* insert(Node*head,int newdata,int node){
    Node* newnode=new Node(newdata);
    Node* temp=head;
    while(temp!=nullptr&&temp->data!=node){
        temp=temp->next;
       
    }
    if(temp!=nullptr){
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;
}
Node* deletehead(Node* head){
    if(head==NULL)return NULL;
    head=head->next;
    return head;
}
Node* deletetail(Node* head) {
    // Case 1: empty list
    if (head == nullptr)
        return nullptr;

    // Case 2: single node
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* deletetail(Node* head){
    if(head==nullptr)return nullptr;
    if(head->next==nullptr){delete head;
    return nullptr;}
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }

    delete temp->next;
    temp->next=nullptr;
    return head;
}
Node* deleteafter(Node* head,int node){
    Node* temp=head;
    Node* prev;
    while(temp!=NULL&& temp->data!=node){
              prev=temp;
              temp=temp->next;
    }
    if(temp->next!=nullptr){
        prev->next=temp->next;
        free(temp);
    }
    return head;
}

Node* reverse(Node* head){
    Node* temp,*prev=NULL,*curr=head;

   while(curr!=NULL){
    temp=curr->next;
    curr->next=NULL;
    temp->next=curr;
    prev=curr;
    curr=temp;
   }
    return head;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    Node* head=convertLL(arr);
    cout<<"Linked list: ";
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
     int data,node;
     cout<<endl<<"data to insert: ";
     cin>>data;
     cout<<endl<<"after node: ";
     cin>>node;
      head=insert(head,data,node);
    cout<<"After insertion: ";
    Node* temp1=head;
    while(temp1!=nullptr){
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    head=deletehead(head);
    
    cout<<endl<<"After deletion: ";
    Node* temp2=head;
    while(temp2!=nullptr){
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }
    head=convertLL(arr);
    head=deletetail(head);
    cout<<endl<<"After deletion of tail: ";
    Node* temp3=head;
    while(temp3!=nullptr){
        cout<<temp3->data<<" ";
        temp3=temp3->next;
    }

    cout<<endl<<"After reversing: "<<endl;
    head=reverse(head);
    temp3=head;
    while(temp3!=nullptr){
        cout<<temp3->data<<" ";
        temp3=temp3->next;
    }
}