#include <bits/stdc++.h>
using namespace std;

int squareSum(int num){
    int sum = 0;

    while(num > 0){
        int d = num % 10;
        sum += d * d;
        num /= 10;
    }

    return sum;
}

bool happyNumber(int num){
    int slow = num, fast = num;
    do{
        slow = squareSum(slow);
        fast = squareSum(squareSum(fast));
    }while(slow != fast);

    return slow == 1;
}

int main(){
    int num = 19;

    if(happyNumber(num))
        cout << "Happy Number";
    else
        cout << "Not Happy Number";
}