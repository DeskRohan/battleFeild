#include<bits/stdc++.h>
using namespace std;

string con2Bin(int n)
{
    string res;
    while(n!=0)
    {
        if(n%2==0){
            res+='0';
        }
        else{
            res+='1';
        }
        n/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}

void swap2Nos(int a,int b)
{
    a=a^b;
    b=a^b;
    a=a^b;

    cout<<a<<" "<<b;
}

bool ithBitSetLeftShift(int n,int i)
{
    return ((n&(1<<i))?1:0);
}

bool ithBitSetRightShiift(int n,int i)
{
    return(((n>>i)&1)?1:0);
}

int countSetBit(int n)
{
    int cnt=0;
    while(n>0){
        if(n%2==1)  cnt++;
        n/=2;
    }
    return cnt;
}
int main()
{
    //cout<<con2Bin(16);                        //Convert Decimal to Binary
    //swap2Nos(10,20);                          //swap two numbers using bitwise operator
    //cout<<ithBitSetLeftShift(1101,2);         //ith bit set or not using left shift
    //cout<<ithBitSetRightShiift(1101,1);       //ith Bit Set 
    cout<<countSetBit(16);
    return 0;
}