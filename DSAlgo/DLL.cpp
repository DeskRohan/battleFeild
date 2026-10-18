#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* nxt;
    Node* prev;

    Node(int data1, Node* nxt1 = nullptr, Node* prev1 = nullptr) {
        data = data1;
        nxt = nxt1;
        prev = prev1;
    }

    Node(int data1) {
        data = data1;
        nxt = nullptr;
        prev = nullptr;
    }
};

Node* convertVec2DLL(const vector<int> &vec)
{
    if (vec.empty()) return nullptr;
    
    Node* head = new Node(vec[0],nullptr,nullptr);
    Node* prev = head;

    for (int i = 1; i < vec.size(); i++) {
        Node* temp = new Node(vec[i], nullptr, prev);
        prev->nxt = temp;
        prev = temp;
    }
    return head;
}

void traversal(Node* head)
{
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->nxt;
    }
}
Node* deleteHead(Node* head)
{
    Node* back=head;
    head=head->nxt;

    head->prev=nullptr;
    back->nxt=nullptr;
    delete(back);

    return head;
}
Node* deleteTail(Node* head)
{
    Node* tail=head;
    while(tail->nxt!=NULL)
    {
        tail=tail->nxt;
    }
    Node* back=tail->prev;
    back->nxt=nullptr;
    tail->prev=nullptr;
    delete(tail);

    return head; 
}
Node* deleteKEle(Node* head,int K)
{
    Node* temp=head;
    int cnt=0;
    while(temp->nxt)
    {
        cnt++;
        if(cnt==K)
        {
            break;
        }
        temp=temp->nxt;
    }
    temp->prev->nxt=temp->nxt;
    temp->nxt->prev=temp->prev;

    return head;
}

Node* insertHead(Node* head,int data)
{
    Node* temp=head;
    Node* newhead=new Node(data,temp,nullptr);
    return newhead;
}

Node* insertTail(Node* head,int data)
{
    Node* temp=head;
    while(temp->nxt)
    {
        temp=temp->nxt;
    }
    Node* newhead=new Node(data,nullptr,temp);
    temp->nxt=newhead;
    return head;
}

Node* insertKEle(Node* head,int data,int K)
{
    Node* temp=head;
    int cnt=0;
    while(temp->nxt)
    {
        cnt++;
        if(cnt==K)
        {
            break;
        }
        temp=temp->nxt;
    }
    Node* newHead=new Node(data,temp->nxt,temp);
    temp->nxt=newHead;
    if(temp->nxt)   temp->nxt->prev=newHead;
    return head;
}

Node* reverseDLLBrute(Node* head)
{
    vector<int> vec;
    Node* temp=head;
    while(temp)
    {
        vec.push_back(temp->data);
        temp=temp->nxt;
    }
    temp=head;
    int i=vec.size()-1;
    while(temp)
    {
        temp->data=vec[i--];
        temp=temp->nxt;
    }
    return head;
}

Node* reverseDLLOptimal(Node* head)
{
    Node* current=head;
    Node* back=NULL;

    while(current!=NULL)
    {
        back=current->prev;
        current->prev=current->nxt;
        current->nxt=back;

        current=current->prev;
    }

    return back->prev;
}
int main()
{
    vector<int> vec = {1, 3, 2, 4};
    Node* head = convertVec2DLL(vec);
    //traversal(head);                          //Convert vec2DLL
    //traversal(deleteHead(head));              //Delete Head of the DLL
    //traversal(deleteTail(head));              //Delete Tail of the DLL
    //traversal(deleteKEle(head,3));            //Delete the Kth Element of DLL
    //traversal(insertHead(head,10));           //Insert at Head of DLL
    //traversal(insertTail(head,10));           //Insert at Tail of DLL
    //traversal(insertKEle(head,10,3));         //Insert at the Kth position
    traversal(reverseDLLOptimal(head));
    return 0;
}
