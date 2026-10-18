#include<bits/stdc++.h>
using namespace std;

pair<int, int> pairSum(int arr[], int n, int target){
    sort(arr, arr + n);

    int i = 0, j = n - 1;

    while(i < j){
        if(arr[i] + arr[j] == target){
            return {arr[i], arr[j]};
        }
        else if(arr[i] + arr[j] > target){
            j--;
        }
        else{
            i++;
        }
    }

    return {-1, -1};
}

int main()
{
    int arr[5] = {1,3,5,4,2};
    int target = 6;

    pair<int,int> ans = pairSum(arr, 5, target);

    cout << ans.first << " " << ans.second;
}