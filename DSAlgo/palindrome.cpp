#include<bits/stdc++.h>
using namespace std;

int main(){
    string name;
    cout<<"Enter the string: ";
    cin>>name;
    int i = 0, j = name.length() - 1;
    while(i < j){
        if(name[i] != name[j]){
            cout<<"Not Palindrome";
            return 0;
        }else{
            i++;
            j--;
        }
    }
    cout<<"Palindrome String";
    return 0;
}