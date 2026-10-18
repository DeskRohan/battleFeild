#include<bits/stdc++.h>
using namespace std;
void solve(string digits, string output, int index, vector<string>& ans, vector<string> mapping){
    //Base condition
    if(index == digits.length()){
        ans.push_back(output);
        return;
    }
    //Processing
    int number = digits[index] - '0';
    string value = mapping[number];
    for(int i = 0; i < value.length(): i++){
        ans.push_back(value[i]);
        solve(digits, output, index, ans, mapping);
        output.pop_back();
    }
}

vector<string> letterCombination(string digits) {
    vector<string> ans;
    if(digits.length() == 0) return ans;

    string output = "";
    int index = 0;

    vector<string> mapping = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    solve(digits, output, index, ans, mapping);
    return ans;
}


int main(){
    cout<<letterCombination("23");
}