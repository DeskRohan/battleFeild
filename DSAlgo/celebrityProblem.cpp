#include<bits/stdc++.h>
using namespace std;
int celebrityBrute(const vector<vector<int>> &arr)
{
    int n=arr.size();
    vector<int> knowsMe(n,0);
    vector<int> iKnow(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1)
            {
                iKnow[i]++;
                knowsMe[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(knowsMe[i]==n-1 && iKnow[i]==0)
        {
            return i;
        }
    }
    return -1;
}
int celebrityOptimal(vector<vector<int>> &vec)
{
    int n=vec.size();
    int top=0,down=n-1;
    while(top<down){
        if(vec[top][down]==1)
        {
            top+=1;
        }else
        if(vec[down][top]==1)
        {
            down-=1;
        }
        else{
            top++;
            down--;
        }
    }
    if(top>down)    return -1;
    for(int i=0;i<n;i++)
    {
        if(i==top)  continue;
        if((vec[top][i]==1)||(vec[i][top]==0))
        {
            return -1;
        }
    }
    return top;

}
int main()
{
    vector<vector<int>> arr = {
    {0, 1, 1, 1},
    {0, 0, 0, 0}, // Person 1 knows no one
    {0, 1, 0, 1},
    {0, 1, 1, 0}
};
    cout<<celebrityOptimal(arr);
}