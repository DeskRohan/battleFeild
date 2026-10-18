#include <bits/stdc++.h>
using namespace std;


int main(){
    srand(time(0));
    int n = rand() % 1000 + 1;
    cout<<n<<" ";
    string players[2]={"Player A", "Player B"};
    string winner = players[n % 2];
    cout<<winner;
}