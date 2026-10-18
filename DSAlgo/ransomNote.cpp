#include<bits/stdc++.h>
using namespace std;

bool isRansomNote(string r, string m){
    int freq[26]={0};
    for(char c : m){
        freq[tolower(c) - 'a']++;
    }

    for(char c : r){
        freq[tolower(c) - 'a']--;
        if(freq[tolower(c) - 'a'] < 0){
            return false;
        }
    }
    return true;
}
int main(){
    string r = "aabsyhm";
    string m = "abbsmmyhj";
    cout<<isRansomNote(r, m);
}