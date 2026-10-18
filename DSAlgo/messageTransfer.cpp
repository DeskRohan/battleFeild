#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="";
    int count=0;
    int l=0,r=s.length();
    while(l<=r){
        if(s[l]==s[r-1-l]){
            count++;
        }
        l++;
    }
    cout<<count;
}