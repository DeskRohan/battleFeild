#include<bits/stdc++.h>
using namespace std;
vector<int> stockSpanner(const vector<int> &vec)
{
    vector<int> list;
    int n=vec.size();
    for(int i=0;i<n;i++)
    {
        int cnt=1;
        int j=i-1;
        while(j>=0&&vec[j]<=vec[i])
        {
            cnt++;
            j--;
        }
        list.push_back(cnt);
    }
    return list;
}
int main()
{
    vector<int> vec={7,2,1,3,3,1,8};
    int n=vec.size();
    vector<int> ans=stockSpanner(vec);
    for(int i:ans)
    {
        cout<<i<<" ";
    }
}