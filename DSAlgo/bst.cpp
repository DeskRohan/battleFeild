#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

Node* arr2BST(Node *root, int target){
    if(!root){
        Node* temp = new Node(target);
        return temp;
    }

    if(target < root->data)
        root->left = arr2BST(root->left, target);
    else
        root->right = arr2BST(root->right, target);

    return root;
}

void kSum(Node *root, int &sum, int &k){
    if(!root)   return;
    kSum(root->left, sum, k);
    if(k > 0){
        sum += root->data;
        k--;
    }
    kSum(root->right, sum, k);
}

int LCA(Node * root, int n1, int n2){
    if(!root)   return 0;

    vector<int> pathN1(0);
    vector<int> parthN2(0);

    // for n1
    if(n1 > root->data){
        pathN1.push_back(root->data);
        LCA(root->right, n1, n2);
    }

    if(n1 < root->data){
        pathN1.push_back(root->data);
        LCA(root->left, n1, n2);
    }

    if(root->data == n1){
        pathN1.push_back(root->data);
    }

    // for n2
    if(n2 > root->data){
        pathN2.push_back(root->data);
        LCA(root->right, n1, n2);
    }

    if(n2 < root->data){
        pathN2.push_back(root->data);
        LCA(root->left, n1, n2);
    }

    if(root->data == n2){
        pathN2.push_back(root->data);
    }

    for(int i = 0 ; i < (pathN1.size() > pathN2.size())?pathN1.size(): pathN2.size(); i++){
        if(pathN1[i] != pathN2[i]){
            return pathN1[i-1];
        }
    }
}
int main(){
    int arr[9] = {8,6,12,4,7,9,14,3,5};

    Node* root = NULL;

    for(int i = 0; i < 9; i++){
        root = arr2BST(root, arr[i]);
    }

    int sum = 0;
    int k = 3;
    kSum(root, sum, k);
    cout<<sum;
}