#include<bits/stdc++.h>
using namespace std;
int checkDigit(int num){
    vector<int> mark(10,0);
    while(num){
        if(mark[num % 10]++) return 0;
        num/=10;
    }
    return 1;
}
int digitCount(int n1, int n2, int count){
    for(int i=n1 ; i <= n2 ; i++){
        count += checkDigit(i);
    }
    return count;
}
int main(){
    cout<<digitCount(1,9,0);
}