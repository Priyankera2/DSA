#include<bits/stdc++.h>
using namespace std;
int linearsearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if (arr[i]==target)return i;
    }
    return -1;
}

int binarysearch(int arr[],int n,int target){
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target)return mid;
        else if(arr[mid]>target){
            high=mid-1;
        }
        else low=mid+1;
    }
    return -1;
}

int maxProfit(int arr[],int n){
    int maxi=0;
    int s=0;
    int b=0;
    for(int i=0;i<n;i++){
        
    }
   
    return maxi;
}
void selection(int arr[],int n){
    for(int i=0;i<n;i++){
        int mini=i+1;
        for(int j=1+i;j<n;j++){
           if(arr[j]<arr[mini])mini=j;
        }
        if(mini<arr[i])swap(arr[mini],arr[i]);
    }
}
void insertion(int arr[],int n){
    for(int i=1;i<n;i++){
        while(arr[i-1]>arr[i])swap(arr[i],arr[i-1]);
    }
}
int main(){
    int arr1[]={29,72,98,13,87,66,52,51,36};
    /*int arr2[]={4,5,6,7};
    int arr3[9];
    int i=0,j=8;
    while(i<5&&j>-1){
        arr3[i]=arr1[i];
        i++;
        arr3[j]=arr2[j-4-1];
        j--;
    }
    while(i<5){
        arr3[i]=arr1[i];
        i++;
    }
    while(j>-1){
        arr3[j]=arr2[j-4-1];
        j--;
    }
    cout<<"merge array: "<<endl;
    for(int num:arr3){
        cout<<num<<" ";
    }
    
    int n=8;
    int s1[n];
    int s2[n/2];
    int k=0;
    while(k<n/2);
    s1[k]=arr3[k];
    s2[k]=arr3[k+n/2];
    k++;
    cout<<endl<<"Splitted arrays: "<<endl;

    for(int num:s1)cout<<num<<" ";
    cout<<endl;
    for(int num:s2)cout<<num<<" ";*/
    cout<<"linear search : "<<linearsearch(arr1,5,3)<<endl<<"Binary search: "<<binarysearch(arr1,5,5)<<endl;
    insertion(arr1,9);
    for(int num:arr1)cout<<num<<" ";
    cout<<endl;
    selection(arr1,9);
    for(int num:arr1){
        cout<<num<<" ";
    }

    
}