#include<bits/stdc++.h>
using namespace std;

bool isMountain(int arr, int n){
    for(int i = 0 ; i < n/2 ; i++){
        if(arr[i] < arr[i+1]){
            return true;
        }
    }
    for(int i = n/2 ; i < n ; i++){
        if(arr[i] > arr[i+1]){
            return true;
        }
    }
    return false;
}
int main(){
    int arr[7]={10, 20, 30, 40, 30, 20, 10};
    cout<<isMountain(arr, 7);
}