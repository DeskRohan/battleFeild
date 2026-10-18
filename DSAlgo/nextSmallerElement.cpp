#include<bits/stdc++.h>
#include<stack>
using namespace std;
vector<int> nextSmallerElement(const vector<int> &vec)
{
    stack<int> st;//stores index
    vector<int> ans(vec);//stores discounted answers;
    for(int i=0;i<vec.size();i++)
    {
        while(!st.empty()&&vec[st.top()]>vec[i])
        {
            ans[st.top()]=vec[st.top()]-vec[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
int main()
{
    vector<int> vec={7,9,12,10,14,8,3,6,9};
    vector<int> ans=nextSmallerElement(vec);
    for(int i:ans)
    {
        cout<<i<<" ";
    }
}