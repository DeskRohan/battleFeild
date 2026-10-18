#include <bits/stdc++.h>
using namespace std;

string removeKthDigit(string s, int k) {
    stack<char> st;
    int n = s.length();

    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top() > s[i] && k > 0) {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }

    while(k > 0) {
        st.pop();
        k--;
    }

    string res = "";
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());

    // Remove leading zeros
    while(!res.empty() && res[0] == '0') res.erase(res.begin());

    if(res.empty()) return "0";
    return res;
}

int main() {
    string num = "1432219";
    int k = 3;
    cout << removeKthDigit(num, k) << endl; // Output: 1219
    return 0;
}
