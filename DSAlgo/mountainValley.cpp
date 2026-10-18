#include<bits/stdc++.h>
using namespace std;

bool checkRight(int a, int b){
    return a < b;
}

bool checkLeft(int a, int b){
    return a > b;
}

int isMountain(int arr[], int n){
    int i = 0, j = 1, k = 2, cnt = 0;
    while(k < n){
        if(arr[j] == arr[k]){
            k++;
            continue;
        }

         if(arr[i] == arr[j]){
            j++;
            k++;
            continue;
        }

        if(checkLeft(arr[j], arr[i]) && checkLeft(arr[j], arr[k])){
            cnt++;
            i = j;
            j = k;
            k = j + 1;
        }
        else{
            i++;
            j++;
            k++;
        }
    }
    return cnt;
}
int main(){
    int arr[6]={2, 4, 1, 1, 6, 5};
    cout<<isMountain(arr, 6);
}