#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n==0)
        return 1;
    int small = factorial(n-1);
    int big = n * small;
    return big;
}

int power(int n){
    if(n==0)
        return 1;
    int smaller = power(n-1);
    int bigger = 2 * smaller;
    return bigger;
}

void printCount(int n){
    if(n==0)
        return;
    cout << n << " ";
    printCount(n-1);
}

void walkingProblem(int src, int dest){
    if(src == dest){
        cout << "Reached Home";
        return;
    }
    walkingProblem(src+1, dest);
}

int fibonaciiNumber(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fibonaciiNumber(n-1) + fibonaciiNumber(n-2);
}

bool isSorted(int arr[],int n){
    if(n==0 || n==1)
        return true;
    if(arr[0] > arr[1])
        return false;
    return isSorted(arr+1, n-1);
}

int arrSum(int arr[], int n){
    static int sum = 0;
    static int cnt = 0;
    if(cnt == n)
        return sum;
    sum += arr[cnt];
    cnt++;
    return arrSum(arr, n);
}

bool linearSearch(int arr[], int n, int key){
    if(n==0)
        return false;
    if(arr[0] == key)
        return true;
    return linearSearch(arr+1, n-1, key);
}

bool binSearch(int arr[], int n, int key){
    if(n==0)
        return false;
    int mid = n/2;
    if(arr[mid] == key)
        return true;
    if(arr[mid] > key)
        return binSearch(arr, mid, key);
    return binSearch(arr+mid+1, n-mid-1, key);
}

string strReverse(string& str,int i, int j){
    if(i>=j)
        return str;
    swap(str[i],str[j]);
    return strReverse(str,i+1,j-1);
}

bool palindrome(string str, int i, int j){
    if(i>=j)
        return true;
    if(str[i]==str[j])
        return palindrome(str,i+1,j-1);
    return false;
}

long long pow(int n, int m){
    if(m==0)
        return 1;
    
    return n * pow(n, m-1);
}

long long powerr(int n, int m){
    long long result = 1;
    while(m){
        result = result * n;
        m--;
    }
    return result;
}

void solve(string digits, string output, int index,
           vector<string>& ans, vector<string> mapping){
    if(index == digits.length()){
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];

    for(int i = 0; i < value.length(); i++){
        output.push_back(value[i]);
        solve(digits, output, index+1, ans, mapping);
        output.pop_back();
    }
}

vector<string> letterCombination(string digits){
    vector<string> ans;
    string output;
    int index = 0;

    vector<string> mapping = {
        " ", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    solve(digits, output, index, ans, mapping);
    return ans;
}

void bubbleSort(int arr[],int n){
    if(n==0 || n==1)
        return;
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    bubbleSort(arr, n-1);
}

int countOcccurance(int arr[], int n, int key){
    int cnt = 0;
    if(n==0)
        return cnt;
    if(arr[0] == key)
        cnt++;
    return cnt + countOcccurance(arr+1, n-1, key);
}

int kSum(vector<int> vec, int sum, int index){
    int n = vec.size();

    // Base Condition:
    if(sum == 0)    return 1;
    if(sum < 0 || index > n)    return 0;

    //Exlude number
    int exclude = kSum(vec, sum, index+1);

    //Include number
    int include = kSum(vec, sum - vec[index], index+1);

    return exclude + include;

}

int kSumZero(vector<int> vec, int sum, int index){
    int n = vec.size();

    // Base Condition:
    if(index == n)  return sum == 0;
    //Meaning of return sum == 0
    // {
    //     if(sum ==0 )    return 1;
    //     else return 0;
    // }

    //Exlude number
    int exclude = kSumZero(vec, sum, index+1);

    //Include number
    int include = kSumZero(vec, sum - vec[index], index+1);

    return exclude + include;
}

int kSumRepeate(vector<int> vec, int sum, int index){
    int n = vec.size();

    // Base Condition:
    if(sum == 0)    return 1;
    if(sum < 0 || index > n)    return 0;

    //Exlude number
    int exclude = kSumRepeate(vec, sum, index+1);

    //Include number
    int include = kSumRepeate(vec, sum - vec[index], index);

    return exclude + include;

}

int permutation(vector<int>& arr, vector<vector<int>>& ans, vector<int> visited, vector<int> temp){

    if(temp.size() == arr.size()){
        ans.push_back(temp);
        return 0;
    }

    for(int i = 0; i < arr.size(); i++){
        if(visited[i] == 0){
            visited[i] = 1;
            temp.push_back(arr[i]);
            permutation(arr, ans, visited, temp);
            visited[i] = 0;
            temp.pop_back();
        }
    }
    return 0;
}

void permutationWithoutExtraSpace(vector<int>& vec, vector<vector<int>>& ans, int index){
    if(index == vec.size()){
        ans.push_back(vec);
        return;
    }

    for(int i = index ; i < vec.size() ; i++){
        swap(vec[i], vec[index]);
        permutationWithoutExtraSpace(vec, ans, index+1);
        swap(vec[i], vec[index]);
    }
}

void permutationWithRepeatation(vector<int>& vec, vector<vector<int>>& ans, int index){
    if(index == vec.size()){
        ans.push_back(vec);
        return;
    }
    vector<bool> map(21,0);
    for(int i=index ; i < vec.size() ; i++){
        if(map[vec[i]+10] == 0){
            swap(vec[i], vec[index]);
            permutationWithRepeatation(vec, ans, index+1);
            swap(vec[i], vec[index]);
            map[vec[i]+10] = 1;
        }
    }
}

int waysToSum(int arr[], int size, int sum){
    if(sum == 0)    return 1;
    if(sum < 0)     return 0;
    int ans = 0;
    for(int i = 0 ; i < size ; i++ ){
        ans = ans + waysToSum(arr, size, sum-arr[i]);
    }
    return ans;
}

void toh(int n, int src, int help, int dest){
    if(n == 1){
        cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
        return;
    }
    toh(n-1, src, dest, help);
    cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    toh(n-1, help, src, dest);
}

int josephusProblem(vector<bool> &person, int n, int index, int personLeft, int k) {

    // Base case: only one alive
    if (personLeft == 1) {
        for (int i = 0; i < n; i++) {
            if (!person[i]) return i;   // alive person
        }
    }

    // Move (k-1) alive persons
    int steps = (k - 1) % personLeft;

    while (steps--) {
        do {
            index = (index + 1) % n;
        } while (person[index]);   // skip dead
    }

    // Kill this person
    person[index] = true;

    // Move index to next alive
    do {
        index = (index + 1) % n;
    } while (person[index]);

    return josephusProblem(person, n, index, personLeft - 1, k);
}

void print1toN(int N){
    if(N > 0){
        cout<<N;
        print1toN(N-1);
    }
}
void reverse(char *ch){
    

}
int main(){

    // BASIC INPUT
    // int n;
    // cin >> n;

    // FACTORIAL
    // cout << factorial(n) << endl;

    // POWER OF 2 
    // cout << power(n) << endl;

    // PRINT COUNT 
    // printCount(10);
    // cout << endl;

    // WALKING PROBLEM 
    // int src = 1, dest = 10;
    // walkingProblem(src, dest);
    // cout << endl;

    // FIBONACCI ----------
    // cout << fibonaciiNumber(7) << endl;

    // ARRAY DECLARATION 
    //int arr[5] = {1, 3, 3, 5, 7};

    // CHECK SORTED 
    // cout << isSorted(arr, 5) << endl;

    // ARRAY SUM 
    // cout << arrSum(arr, 5) << endl;

    // LINEAR SEARCH 
    // cout << linearSearch(arr, 5, 5) << endl;

    // BINARY SEARCH 
    // bubbleSort(arr, 5);
    // cout << binSearch(arr, 5, 3) << endl;

    // STRING OPERATIONS 
    // string str = "ABA";
    // cout << palindrome(str, 0, str.length() - 1) << endl;
    // cout << strReverse(str, 0, str.length() - 1) << endl;

    // POWER (x^n) 
    //cout << powerr(2, 5) << endl;

    // COUNT OCCURRENCE 
    // cout << countOcccurance(arr, 5, 3) << endl;

    // LETTER COMBINATIONS 
    // vector<string> res = letterCombination("23");
    // for(string s : res)
    //     cout << s << " ";

    // K Sum
    // vector<int> vec = {3, 4, 1};
    // cout<<kSum(vec, 9, 0);

    // K Sum with Zero
    // vector<int> vec = {1, 0};
    // cout<<kSumZero(vec, 1, 0);

    // K Sum with repetation allowed
    // vector<int> vec = {2, 3, 4};
    // cout<<kSumRepeate(vec, 6, 0);

    // Permutation
    // vector<int> vec = {1, 1, 2};
    // vector<vector<int>> ans;
    // vector<int> visited(vec.size(),0);
    // vector<int> temp;
    // permutationWithRepeatation(vec, ans, 0);
    // for(auto &p : ans){
    //     for(int x : p) cout << x << " ";
    //     cout << endl;
    // }

    // Ways to Sum
    // int arr[3] = {1, 5, 6};
    // cout<<waysToSum(arr, 3, 7);

    // Tower of Hanio
    //toh(5, 1, 2, 3);

    // Josephus Problem
    // vector<bool> person(5,0);
    // cout<<josephusProblem(person, 5, 0, 5, 3);

    print1toN(10);

    return 0;
}

