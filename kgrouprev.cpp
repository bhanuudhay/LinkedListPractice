#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next ;
    Node(int  value)
    {
        data = value;
        next = NULL;
    }
};

void insertEnd(Node * &head ,Node * &tail , int d )
{
    Node * newNode=new Node(d);
    if(tail == NULL)
    {
        head = tail= newNode;
        return ;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void traverse(Node * &head){
    Node * temp = head;
    if(head == NULL)
    {
        cout << "No element exist"<<endl;
        return;
    }
    while(temp!=NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
}

Node* revGroup(Node * &head , int k)
{
    if(head == NULL )
    {
        return NULL;
    }
    Node *next = NULL;
    Node *curr = head;
    Node *prev =NULL;
    int count  = 0;
    while(curr!=NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr =next;
        count++;
    }

    if(next!=NULL)
    {
        head->next = revGroup(next,k);
    }
    return prev;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertEnd(head,tail,10);
    insertEnd(head,tail,20);
    insertEnd(head,tail,30);
    insertEnd(head,tail,40);
    insertEnd(head,tail,50);
    insertEnd(head,tail,60);
    Node * newNode = revGroup(head ,2);
    head = newNode;
    traverse(head);

    

}