#include<bits/stdc++.h>
using namespace std;

int mirrorReflection(int p, int q){
    while(!(p & 1) && !(q & 1)){
        p /= 2;
        q /= 2;
    }
    if((q & 1) && !(p & 1))     return 2;
    if(!(q & 1) && (p & 1))     return 0;
    return 1;
}

int main(){
    int p = 4, q = 2;
    cout<<mirrorReflection(p, q);
}