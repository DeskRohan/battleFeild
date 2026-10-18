#include<bits/stdc++.h>
using namespace std;

class Human{
    private:
    int a;
    
    protected:
    int b;
    
    public:
    int c;

    void func(){
        a = 10;
        b = 20;
        c = 30;
    }
};

int main(){
    Human H;
    H.func();
}