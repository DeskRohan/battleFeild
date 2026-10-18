#include<bits/stdc++.h>
using namespace std;

stack<int> astroidCollision(const vector<int> &vec)
{
    stack<int> st;
    for(int i=0;i<vec.size();i++){
        if(vec.at(i)>0){
            st.push(vec.at(i));
        }
        else{
            int check=vec.at(i)*(-1);
            int destroyed=0;
            while(!st.empty()&&st.top()>0){
                if(st.top()==check)
                {
                    st.pop();
                    destroyed=1;
                    break;
                }
                else if(st.top()>check){
                    destroyed=1;
                    break;
                }else{
                    st.pop();
                }
            }
            if(!destroyed)
            {
                st.push(vec[i]);
            }
        }
    }
    return st;
}

int main()
{
    vector<int> vec={4,7,1,1,2,-3,-7,17,15,-16};
    stack<int> ans=astroidCollision(vec);
    vector<int> output;
    while(!ans.empty())
    {
        output.push_back(ans.top());
        ans.pop();
    }
    reverse(output.begin(),output.end());
    for(int i:output){
        cout<<i<<" ";
    }
}