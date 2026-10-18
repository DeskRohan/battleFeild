#include<bits/stdc++.h>
using namespace std;
vector<int> slideingWindowMax(const vector<int> &vec,int k)
{
    int n=vec.size();
    vector<int> list;
    deque<int> dq;
    for(int i=0;i<n;i++){
        if(!dq.empty()&&dq.front()<=i-k)
        {
            dq.pop_front();
        }
        while(!dq.empty()&&vec[dq.back()]<=vec[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1)   list.push_back(vec[dq.front()]);
    }
    return list;
}
int main()
{
    vector<int> vec={1,3,-1,-3,5,3,2,1,6};
    vector<int> ans=slideingWindowMax(vec,3);
    for(int i : ans)
    {
        cout<<i;
    }
}