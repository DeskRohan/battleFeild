#include<bits/stdc++.h>
using namespace std;
void printBinary(int num){
    for(int i = 10 ; i >= 0 ; --i){
        cout<<((num>>i) & 1);
    }
    cout<<endl;
}

bool isSet(int i, int a){
    if((a&(1<<i))!=0){
        return true;
    }
    return false;
}

int main(){
    // int a = 9;
    // printBinary(a);
    // //cout<<isSet(0, a);
    // printBinary(a | (1<<4));
    char a = 'a';
    char A = a & (~(1<<5));
    cout<<A;


}