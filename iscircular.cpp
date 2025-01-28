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

    traverse(head);


}