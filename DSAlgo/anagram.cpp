#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t){
    if(s.length() != t.length()){
        return false;
    }
    int freq[26]={0};
    for(int i =0 ; i < s.size() ; i++){
        freq[tolower(s[i]) - 'a']++;
        freq[tolower(t[i]) - 'a']--;
    }

    for(int i = 0 ; i < 26 ; i++){
        if(freq[i] != 0)    return false;
    }

    return true;
}
int main(){
    string s = "Misten";
    string t = "istenL";
    cout<<isAnagram(s, t);
}