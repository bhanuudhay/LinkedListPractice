#include<iostream>
using namespace std;
class Node
{
    public:

    int value;
    Node *next;
    Node(int d)
    {
        value  =d;
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

void traverse(Node * &head)
{
    if(head == NULL)
    {
        cout <<"No element"<<endl;
    }
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->value <<" ";
        temp = temp->next;
    }
}
void rev(Node *&head , Node * &curr ,Node * &prev)
{
    if(curr == NULL)
    {
        head = prev;
        return;
    }
    Node * forward = curr->next;
    rev(head,forward,curr);
    curr->next = prev;
}
int main()
{
    Node * head = NULL;
    Node *tail = NULL;
    Node *prev = NULL;
    insertEnd(head,tail,10);
    insertEnd(head,tail,20);
    insertEnd(head,tail,30);
    insertEnd(head,tail,40);
    traverse(head);

    cout << endl << "after reversing the node"<<endl;
    Node  *curr =head;
    rev(head ,curr,prev);
    traverse(head);


} 