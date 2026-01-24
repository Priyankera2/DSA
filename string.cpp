#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
        map<char,int>mp;
        mp['I']=1;mp['V']=5;mp['X']=10;mp['L']=50;mp['C']=100;mp['D']=500;mp['M']=1000;
        int n=s.length();
        int num=mp[s[n-1]];
        int i=n-1;
        while(i>0){
            if(mp[s[i-1]]<mp[s[i]])num-=mp[s[i-1]];
            else num+=mp[s[i-1]];
            i--;
        }
        return num;
}

int main(){
   
    string s;
    cin>>s;
    cout<<romanToInt(s);
}

#include<btsdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<){
        
    }
}