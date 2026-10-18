//1.
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<bits/stdc++.h>
using namespace std;
// void reverse(std::vector<int> &arr, int start, int end){
//     int i = start, j = end;
//     while(i <= j){
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//         i++;
//         j--;
//     }
// }

// int main(){
//     std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
//     int n = 7;
//     int k = 3;
//     k %= n;
//     reverse(arr, 0, n - k - 1);
//     reverse(arr, n - k, n - 1);
//     reverse(arr, 0, n - 1);
//     for(int i = 0 ; i < n ; i++){
//         std::cout<<arr[i]<<" ";
//     }
// }

//2.
// int main(){
//     vector<string> set()={"2","1","+","3","*"};
//     stack<int> st;
//     int i = 0;
//     for(auto x : set){
//         if(x == "+" || x == "-" || x == "/" || x == "*"){
//             int val2 = st.top();
//             st.pop();
//             int val1 = st.top();
//             st.pop();
//             if(x == "+")    st.push(val1 + val2);
//             else if(x == "-")   st.push(val2 - val1);
//             else if(x == "*")   st.push(val2 * val1);
//             else st.push(val2 / val1);
//         }else{
//             st.push(stoi(x));
//         }
//     }
//     cout<<st.top();
// }

//3.
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> arrA = {1,3,5,7,9};
//     vector<int> arrB = {2,4,6,8,10};
//     vector<int> ans;

//     int i = 0, j = 0;

//     while(i < arrA.size() && j < arrB.size()){
//         if(arrA[i] < arrB[j]){
//             ans.push_back(arrA[i]);
//             i++;
//         } else {
//             ans.push_back(arrB[j]);
//             j++;
//         }
//     }

//     while(i < arrA.size()){
//         ans.push_back(arrA[i]);
//         i++;
//     }
//     while(j < arrB.size()){
//         ans.push_back(arrB[j]);
//         j++;
//     }

//     int median = 0;
//     int n = ans.size();
//     if(n % 2 == 0){
//         median = (ans[n/2 - 1] + ans[n/2]) / 2;
//     } else {
//         median = ans[n/2];
//     }

//     cout << median;
// }

//5. Valid Palindrome
// int main(){
//     string s;
//     getline(cin, s);
//     int i = 0, j = s.length()-1;
//     while(i < j){
//         char start = tolower(s[i]);
//         char end = tolower(s[j]);
//         if(start ==' ' || !isalnum(start) || !isalnum(end)){
//             i++;
//             continue;
//         }
//         if(end ==' ' || !isalnum(start) || !isalnum(end)){
//             j--;
//             continue;
//         }
//         if(start != end){
//             cout<<"Not Palindrome";
//             return 0;
//         }else{
//             i++;
//             j--;
//         }
//     }
//     cout<<"Palindromic String";
// }

//6. Minimum size subarray sum
// int main() {
//     int n, target;
//     cin >> n >> target;

//     vector<int> nums(n);

//     for (int i = 0; i < n; i++)
//         cin >> nums[i];

//     int left = 0;
//     int sum = 0;
//     int ans = INT_MAX;

//     for (int right = 0; right < n; right++) {
//         sum += nums[right];

//         while (sum >= target) {
//             ans = min(ans, right - left + 1);
//             sum -= nums[left];
//             left++;
//         }
//     }

//     if (ans == INT_MAX)
//         cout << 0;
//     else
//         cout << ans;

//     return 0;
// }

//7. Insertion in sorted array
// int main(){
//     int n;
//     cin>>n;

//     vector<int> vec(n, 0);

//     for(int i = 0 ; i < vec.size() ; i++){
//         cin>>vec.at(i);
//     }

//     int key;
//     cin>>key;

//     for(int i = 0 ; i < n ; i++){
//         if(vec.at(i) == key){
//             cout<<i;
//             return 0;
//         }else
//         if(vec.at(i) > key){
//             cout<<i;
//             return 0;
//         }
//     }
// }

//8. longest consecutive sequence
// int main(){
//     int n;
//     cin>>n;

//     vector<int> vec(n, 0);
//     for(int i = 0 ; i < n ; i++){
//         cin>>vec.at(i);
//     }

//     unordered_set<int> set;

//     for(auto x : vec){
//         set.insert(x);
//     }
    
//     int longest = 0;

//     for(auto x : set){
//         if(set.find(x - 1) == set.end()){
//             int current = x;
//             int length = 1;

//             while(set.find(current + 1) != set.end()){
//                 length++;
//                 current++;
//             }

//             longest = max(longest, length);
//         }
//     }
//     cout<<longest;
//     return 0;
// }

//Insertion in sorted array optimal 
// int main(){
//     int n;
//     cin>>n;

//     vector<int> vec(n, 0);
//     for(int i = 0 ; i < n ; i++){
//         cin>>vec.at(i);
//     }

//     int key;
//     cin>>key;

//     int i = 0, j = n;
//     while(i < j){
//         int mid = i + (j - i) / 2;

//         if(vec.at(mid) == key){
//             cout<<mid;
//         }
//         if(vec.at(mid) > key){
//             j = mid - 1;
//         }
//         if(vec.at(i) < key){
//             i = mid + 1;
//         }
//     }
//     cout<<i-1;
// }

//Add Binary

// int main() {
//     string a, b;
//     cin >> a >> b;

//     string ans = "";
//     int i = a.size() - 1;
//     int j = b.size() - 1;
//     int carry = 0;

//     while (i >= 0 || j >= 0 || carry) {
//         int sum = carry;

//         if (i >= 0) sum += a[i--] - '0';
//         if (j >= 0) sum += b[j--] - '0';

//         ans += (sum % 2) + '0';
//         carry = sum / 2;
//     }

//     reverse(ans.begin(), ans.end());
//     cout << ans;

//     return 0;
// }

//Triangle - minimum path sum
// int main() {
//     int n;
//     cin >> n;

//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         int smallest = INT_MAX;
//         for (int j = 0; j <= i; j++) {
//             int x;
//             cin >> x;
//             smallest =  min(smallest, x);
//         }
//         sum += smallest;
//     }
//     cout<<sum;
// }

//Contains duplicates
// int main(){
//     int n;
//     cin>>n;

//     vector<int> vec(n, 0);
//     for(int i = 0 ; i < n; i++){
//         cin>>vec.at(i);
//     }

//     vector<int> freq(n, 0);
//     for(auto x : vec){
//         freq[x]++;
//     }

//     for(auto x : freq){
//         if(x >= 2){
//             cout<<"true";
//             return 0;
//         }
//     }
//     cout<<"false";
//     return 0;
// }

//Remove duplicates from the sorted array
// int main() {
//     int n;
//     cin >> n;

//     vector<int> vec(n);
//     for (int i = 0; i < n; i++)
//         cin >> vec[i];

//     unordered_map<int, int> mp;

//     for (auto x : vec)
//         mp[x]++;

//     vec.clear();

//     for (auto x : mp)
//         vec.push_back(x.first);

//     int i = 0 , j = vec.size() - 1;

//     while(i < j){
//         int temp = vec.at(i);
//         vec.at(i) = vec.at(j);
//         vec.at(j) = temp;
//         i++;
//         j--;
//     }

//     for (auto x : vec)
//         cout << x << " ";
    
//     cout<<endl<<vec.size();
// }

//Remove duplicates from sorted array II
int main() {
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++){
      cin>>arr[i];
    }

    unordered_map<int,int>mpp;
    
    for(int i=0;i<n;i++){
      mpp[arr[i]]++;
       
      arr.pop_back();
    }

    for(auto &it:mpp){
      int count=0;
      if(it.second>1){
        while(it.second){
          arr.push_back(it.first);
          count++;
          if(count==2) break;
        }
      }
      else 
      arr.push_back(it.first);
    }

    int i=0,j=arr.size()-1;
    while(i<j){
      swap(arr[i++],arr[j--]);
    }

    for(int i=0;i<arr.size();i++){
      cout<<arr[i]<<" ";
    }
    
    cout<<endl<<arr.size();

    return 0;
}