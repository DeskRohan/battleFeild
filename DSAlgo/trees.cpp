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

Node* binaryTree(){
    int x;
    cin>>x;

    if(x == -1){
        return NULL;
    }
    Node *temp = new Node(x);

    //left child
    cout<<"Enter the left child of : "<<x<<endl;
    temp->left = binaryTree();

    //right child
    cout<<"Enter the right child of : "<<x<<endl;
    temp->right = binaryTree();
    return temp;
}

void preorder(Node *root){
    if(root == NULL)    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root){
    if(root == NULL)    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node *root){
    if(root == NULL)    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

vector<int> levelorder(Node* root){
    vector<int> ans;

    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        ans.push_back(temp->data);

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
    return ans;
}

int sizeBT(Node *root){
    if(root == NULL)    return 0;
    return 1 + sizeBT(root->left) + sizeBT(root->right);
}

int sumBT(Node *root){
    if(root == NULL)    return 0;
    return root->data + sumBT(root->left) + sumBT(root->right);
}

int countLeafNodes(Node *root){
    if(root == NULL)    return 0;
    
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int heightBT(Node* root){
    if(root == NULL)    return 0;

    return (1 + max(heightBT(root->left),heightBT(root->right)));
}

bool isIdentical(Node *r1, Node *r2){
    if(r1 == NULL && r2 == NULL){
        return 1;
    }
    if((r1 == NULL && r2) || (r1 && r2 == NULL)){
        return 0;
    }
    if(r1->data != r2->data){
        return 0;
    }

    return isIdentical(r1->left, r2->left) && isIdentical(r1->right,r2->right);
}

void mirrorBT(Node *root){
    if(root == NULL)    return;

    Node *temp = root->right;
    root->right = root->left;
    root->left = temp;

    mirrorBT(root->left);
    mirrorBT(root->right);
}

int heightCal(Node *root, bool &valid){
    if(root == NULL)    return 0;
    int l = heightCal(root->left, valid);
    int r = heightCal(root->right, valid);

    if(abs(l-r) > 1)    valid = false;

    return 1 + max(l, r);
}

bool isBalance(Node *root){
    bool valid = true;
    heightCal(root, valid);
    return valid;
}

vector<int> findSpiral(Node *root){
    if(root == NULL)    return{};

    stack<Node*> RL;
    stack<Node*> LR;
    RL.push(root);
    vector<int> ans;
    while(!LR.empty() || !RL.empty()){
        // Right to Left
        if(!RL.empty()){
            while(!RL.empty()){
                Node *temp = RL.top();
                RL.pop();
                ans.push_back(temp->data);
                if(temp->left)     LR.push(temp->left);
                if(temp->right)      LR.push(temp->right);
            }
        }else//Left to Right
        {
            while(!LR.empty()){
                Node *temp = LR.top();
                LR.pop();
                ans.push_back(temp->data);
                if(temp->right)     RL.push(temp->right);
                if(temp->left)      RL.push(temp->left);
            }
        }
    }
    return ans;
}

bool checkParent(Node *root, int a, int b){
    if(!root)   return 0;
    if(root->left && root->right){
        if(root->left->data == a && root->right->data == b) return 1;
        if(root->left->data == b && root->right->data == a) return 1;
    }
    return checkParent(root->left, a, b) || checkParent(root->right, a, b);
}

bool isCousin(Node *root, int a, int b){
    queue<Node*> q;
    q.push(root);
    int l1 = -1, l2 = -1;
    int level = 0;
    while(!q.empty()){
        int n = q.size();
        while(n--){
            Node *temp = q.front();
            q.pop();
            if(temp->data == a)     l1 = level;
            if(temp->data == b)     l2 = level;
            if(temp->left)          q.push(temp->left);
            if(temp->right)         q.push(temp->right);
        }
        level++;
        if(l1 != l2)    return 0;
        if(l1 != -1)    break;
    }
    return !checkParent(root, a, b);
}

vector<int> leftView(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        ans.push_back(q.front()->data);
        int n = q.size();
        while(n--){
            Node *temp = q.front();
            q.pop();
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return ans;
}

void rightView(Node *root, int level, vector<int> &ans){
    if(!root) return;

    if(level == ans.size())
        ans.push_back(root->data);

    rightView(root->right, level+1, ans);
    rightView(root->left, level+1, ans);
}

int diameter(Node *root){
    if(!root)   return 0;
    int left = diameter(root->left);
    int right = diamter(root->right);

    return 1 + left + right;
}

int main(){
    // Creating Binary Tree.
    cout<<"Enter the root node: "<<endl;
    Node *root;
    root = binaryTree();
    cout<<endl;

    // cout<<"Create First Tree"<<endl;
    // cout<<"Enter the root node: "<<endl;
    // Node *root1 = binaryTree();

    // cout<<"\nCreate Second Tree"<<endl;
    // cout<<"Enter the root node: "<<endl;
    // Node *root2 = binaryTree();

    // Pre-order traversal.
    // cout<<"PreOrder Traversal: ";
    // preorder(root);
    // cout<<endl;

    // In-order traversal.
    // cout<<"InOrder Travesal: ";
    // inorder(root);
    // cout<<endl;

    // Post-order travesal.
    // cout<<"PostOrder Traversal: ";
    // postorder(root);
    // cout<<endl;

    // Level-Order traversal.
    // cout<<"LevelOrder Traversal: ";
    // vector<int> vec = levelorder(root);
    // for(auto i : vec){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // Size of Binary Tree.
    // cout<<"Size of Binary Tree: "<<sizeBT(root);

    // Sum of Binary Tree.
    // cout<<"Sum of Binary Tree: "<<sumBT(root);
    
    // Count leaf nodes in Binary Tree.
    // cout<<"Count of Leaf Nodes of Binary Tree: "<<countLeafNodes(root);

    // Height of Binary Tree.
    // cout<<"Height of Binary Tree: "<<heightBT(root);

    // Identical Trees
    // cout<<"Trees are: "<<isIdentical(root1, root2);

    // Mirror Binary Trees.

    // Balanced Binary Tree?
    // cout<<"The tree is: "<<isBalance(root);

    // Spiral order traversal.
    // vector<int> result = findSpiral(root);

    // cout << "Spiral Traversal: ";
    // for(int x : result){
    //     cout << x << " ";
    // }

    // Check if roots are Cousine.
    // cout<<"The roots are: "<<isCousin(root, 4, 6);

    // left view of binary tree.
    vector<int> vec;
    rightView(root, 0, vec);
    for(auto it : vec){
        cout<<it<<" ";
    }
}