#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="I Love India And India Is My Country";
    stringstream sso(s);
    vector<string> word;
    string i;
    while(sso >> i){
        word.push_back(i);
    }
    int n=word.size();
    for(int i=n-1;i>=0;i--){
        cout<<word[i]<<" ";
    }
}