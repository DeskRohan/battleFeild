#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOnesIII(const vector<int> &vec, int k){
    int n=vec.size();
    int l,r,maxi,len,zeroCount;
    l=r=maxi=len=zeroCount=0;
    while(r<n){
        if(vec.at(r)==0){
            zeroCount++;
        }
        if(zeroCount<=k){
            len=r-l+1;
            maxi=max(maxi,len);
            r++;
        }else{
            while(zeroCount>k){
                if(vec.at(l)==0){
                    zeroCount--;
                }
                l++;
            }
            r++;
        }
    }
    return maxi;
}
int main()
{
    vector<int> vec={1,1,1,0,0,0,1,1,1,1,0};
    cout<<maxConsecutiveOnesIII(vec,2);
}