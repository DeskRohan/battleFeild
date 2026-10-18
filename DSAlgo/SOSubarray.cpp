#include <bits/stdc++.h>
using namespace std;

int sumOfSubArray(const vector<int> &arr)
{
    int n = arr.size();
    int i = 0, j = 0;
    int loopCount = 1;
    stack<int> st;
    int sum = 0;

    // run until we have processed every element once
    while (loopCount <= n && i < n)           // ✅ guard against out-of-range
    {
        st.push(arr.at(i));
        i++;
        loopCount++;

        if (i == n) {
            j++;
            i = j;                            // ✅ next start index
        }
        if (i < n) {                          // ✅ check again before access
            if (st.top() > arr[i]) {
                st.pop();
                st.push(arr[i]);
            }
        }
        sum += st.top();                      // ✅ move outside the if/else
    }
    return sum;                                // ✅ missing return
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    cout << sumOfSubArray(arr) << '\n';
}
