#include<bits/stdc++.h>
using namespace std;
bool isUglyNumber(int num){
    if(num < 1)     return false;

    while(num % 2 == 0)     num /= 2;
    while(num % 3 == 0)     num /= 3;
    while(num % 5 == 0)     num /= 5;

    return num == 1;
}
int main(){
    cout<<isUglyNumber(14);
}