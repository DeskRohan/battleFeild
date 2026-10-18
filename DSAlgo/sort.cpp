#include<bits/stdc++.h>
using namespace std;

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int arr[5] = {1,3,5,2,4};
    qsort(arr, 5, sizeof(int), compare);
    for(int i = 0 ; i < 5 ; i++){
        cout<<arr[i];
    }
}