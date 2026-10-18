#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* nxt;
    Node(int data1, Node* nxt1 = nullptr) {
        data = data1;
        nxt = nxt1;
    }
};

Node* convertVec2LL(vector<int> &vec) {
    if (vec.empty()) return nullptr;

    Node* head = new Node(vec[0]);
    Node* mover = head;

    for (int i = 1; i < vec.size(); i++) {
        Node* temp = new Node(vec[i]);
        mover->nxt = temp;
        mover = temp;
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
int LengthOfLL(Node *head)
{
    int cnt=0;
    Node* temp=head;
    while(temp)
    {
        temp=temp->nxt;
        cnt++;
    }
    return cnt;
}
int SearchInLL(Node *head,int val)
{
    Node *temp=head;
    while(temp)
    {
        if(temp->data==val)     return 1;
        temp=temp->nxt;
    }
    return 0;
}
Node* DeleteHead(Node* head)
{
    Node* temp=head;
    head=head->nxt;
    delete temp;
    return head;
}
Node* DeleteTail(Node* head)
{
    Node* temp=head;
    if(head==NULL || head->nxt==NULL)
    {
        return NULL;
    }
    while(temp->nxt->nxt!=NULL)
    {
        temp=temp->nxt;
    }
    delete temp->nxt;
    temp->nxt=NULL;
    return head;
}
Node* insertHead(Node* head,int val)
{
    return new Node(100,head);
}
Node* insertTail(Node* head,int val)
{
    if(head==NULL)
    {
        return new Node(val,head);
    }
    Node* temp=head;
    while(temp->nxt!=NULL)
    {
        temp=temp->nxt;
    }
    temp->nxt=new Node(val);
    return head;
}

Node * insertAtPosition(Node* head,int val,int pos)
{
    if(head==NULL)
    {
        if(pos==1)
        {
            return new Node(val);
        }
        else
        return head;
    }
    if(pos==1)
    {
        return new Node(val,head);
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==(pos-1))
        {
            Node* x=new Node(val,temp->nxt);
            temp->nxt=x;
            return head;
        }
        temp=temp->nxt;
    }
    return head;
}

int middleEleBrute(Node* head)
{
    int cnt=0;
    Node* temp=head;
    while(temp)
    {
        cnt++;
        temp=temp->nxt;
    }
    int pos=(cnt)/2;
    temp=head;
    for(int i=0;i<pos;i++)
    {
        temp=temp->nxt;
    }
        return temp->data;
}
int middleEleOptimal(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->nxt!= NULL)
    {
        slow=slow->nxt;
        fast=fast->nxt->nxt;
    }
    return slow->data;
}
Node* reverseBrute(Node* head)
{
    Node* temp=head;
    vector<int> vec;
    while(temp)
    {
        vec.push_back(temp->data);
        temp=temp->nxt;
    }
    temp=head;
    while(temp)
    {
        temp->data=vec.back();
        vec.pop_back();
        temp=temp->nxt;
    }
    return head;
}
int detectLoopBrute(Node* head)
{
    map<Node*,int> mpp;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return 1;
        }
        else
            mpp[temp]=1;
        temp=temp->nxt;
    }
    return 0;
}
int detectLoopOptimal(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->nxt!=NULL)
    {
        slow=slow->nxt;
        fast=fast->nxt->nxt;
        if(slow==fast)
        {
            return 1;
        }
    }
    return 0;
}
Node* findStartLoopBrute(Node* head)
{
    map<Node*,int> mpp;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return temp;
        }
        mpp[temp]=1;
        temp=temp->nxt;
    }
    return nullptr;
}
int LengthOfLoopBrute(Node* head)
{
    map<Node*,int> mpp;
    Node* temp=head;
    int value,timer=1;
    while(temp!=NULL)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return timer-mpp[temp];
        }
    mpp[temp]=timer;
    timer++;
    temp=temp->nxt;
    }
    return 0;
}

int LengthOfLoopOptimal(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL&&fast->nxt!=NULL)
    {
        slow=slow->nxt;
        fast=fast->nxt->nxt;
        if(fast==slow)
        {
            int cnt=1;
            slow=slow->nxt;
            while(slow!=fast)
            {
                cnt++;
                slow=slow->nxt;
            }
            return cnt;
        }
    }
    return 0;
}

int checkPalindromeBrute(Node* head)
{
    vector<int> vec;
    Node* temp=head;
    while(temp!=NULL)
    {
        vec.push_back(temp->data);
        temp=temp->nxt;
    }
    temp=head;
    while(temp!=NULL){
        if(vec.back()!=temp->data)  return 0;
        else    temp=temp->nxt; vec.pop_back();
    }
    return 1;
}
int checkPalindromeOptimal(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->nxt!=NULL)
    {
        slow=slow->nxt;
        fast=fast->nxt->nxt;
    }
        Node *newHead=reverseBrute(slow->nxt);
        Node* first=head;
        Node* second=newHead;

        while(second!=NULL)
        {
            if(first->data!=second->data)
            {
                return 0;
            }
            first=first->nxt;
            second=second->nxt;
        }
        return 1;
}
Node* SegrigateEvenOddIdx(Node* head)
{
    Node* odd=head;
    Node* even=head->nxt;
    Node* evenHead=head->nxt;
    while(even && even->nxt!=NULL)
    {
        odd->nxt=odd->nxt->nxt;
        even->nxt=even->nxt->nxt;

        odd=odd->nxt;
        even=even->nxt;
    }
    odd->nxt=evenHead;
    return head;
}
Node* RemoveNNodeoptimal(Node* head,int n)
{
    Node* slow=head;
    Node* fast=head;
    for(int i=0;i<n;i++)
    {
        fast=fast->nxt;
    }
    while(fast->nxt)
    {
        slow=slow->nxt;
        fast=fast->nxt;
    }
    Node* delNode=slow->nxt;
    slow->nxt=slow->nxt->nxt;
    delete(delNode);
    return head;
}
Node* deleteMiddleBrute(Node* head)
{
    Node* temp=head;
    int cnt=0;
    while(temp)
    {
        cnt++;
        temp=temp->nxt;
    }
    temp=head;
    int res=cnt/2;
    for(int i=0;i<res-1;i++)
    {
        temp=temp->nxt;
    }
    Node* delNode=temp->nxt;
    temp->nxt=temp->nxt->nxt;
    delete(delNode);
    return head;
}
Node* deleteMiddleOptimal(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast->nxt &&  fast->nxt->nxt && fast->nxt->nxt->nxt) 
    {
        slow=slow->nxt;
        fast=fast->nxt->nxt;
    }
    Node* delNode=slow->nxt;
    slow->nxt=slow->nxt->nxt;
    delete(delNode);
    return head;
}
int main() {
    vector<int> vec = {3, 2, 1, 2, 3};
    Node* head = convertVec2LL(vec);              //Convert Vector to Linked List
    //traversal(head);                              Traversal in Linked List
    //cout<<LengthOfLL(head);                       Length Of Linked List
    //cout<<SearchInLL(head,4);                     Search in Linked List
    //head=DeleteHead(head); traversal(head);       Delete Head
    //head=DeleteTail(head); traversal(head);
    //head=insertHead(head,100); traversal(head);   Insert element at the Head
    //head=insertTail(head,100); traversal(head);   Insert element at the Tail
    //head=insertAtPosition(head,100,4); traversal(head);   Insert element at given position
    //cout<<middleEleOptimal(head);
    //head=reverseBrute(head); traversal(head);
    //cout<<detectLoopOptimal(head);                Detect Loop in the Linked List
    //cout<<findStartLoopBrute(head);               Starting point of loop
    //cout<<LengthOfLoopOptimal(head);              Lenght of Loop
    //cout<<checkPalindromeOptimal(head);           Check for Palindrome
    //traversal(SegrigateEvenOddIdx(head));         Segrigate odd and even links
    //traversal(RemoveNNodeoptimal(head,3));        Remove nth Node from end
    traversal(deleteMiddleOptimal(head));
}
