#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data,Node* next){
        this->data=data;
        this->next=next;
    }
};
Node* convertArr2LL(vector<int> &arr){
    Node* head=new Node(arr[0],nullptr);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
            Node* temp=new Node(arr[i],nullptr);
            mover->next=temp;
            mover=mover->next;
    }
    return head;
}
bool checkelementPresent(Node* head,int x){
    while(head){
        if(head->data==x)return true;
        head=head->next;
    }
    return false;
}
int main(){
    vector<int> arr={2,4,7,8};
    Node* head=convertArr2LL(arr);
    int cnt=0; //calculate the length of linked list
   /* while(head){
        cout<<head->data<<" ";
        cnt++;
        head=head->next;
    }
    // cout<<head->data;

    cout<<endl<<cnt<<endl;*/
    cout<<checkelementPresent(head,4);
    return 0;
}
