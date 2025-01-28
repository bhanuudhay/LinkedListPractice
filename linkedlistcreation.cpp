#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(int d)
    {
        data =d;
        next = NULL;
    }
};
void insertBeg(Node* &head, int d)
{
    Node *newNode = new Node(d);
    if(head == NULL)
    {
        head = newNode;
    }
    else{
    newNode->next = head;
    head = newNode;
    }
}
void insertEnd(Node* &head, Node* &tail, int d)
{
    Node *newNode = new Node(d);
    
    if (tail == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
void insertPos(Node * &head,Node * &tail,int pos, int d)
{
    if(pos == 1)
    {
        insertBeg(head,d);
        return;
    }
    Node *temp = head;
    int cnt  = 1;
    while(cnt < pos-1)
    {
        temp= temp->next;
        cnt++;
    }
    if(temp->next == NULL)
    {
        insertEnd(head,tail,d);
        return;
    }
    Node * newNode= new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}
void traverse(Node * head)
{
    if(head  == NULL)
    {
        cout << "No Element"<<endl;
        return;
    }
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node * temp  = NULL;
    Node *tail= NULL;
    insertBeg(temp , 10);
    insertBeg(temp , 20);
    insertBeg(temp , 30);
    insertBeg(temp , 40);
    traverse(temp);
    cout << endl <<"after inserting at end"<<endl;
    insertEnd(temp,tail,10);
    insertEnd(temp,tail,30);
    insertEnd(temp,tail,40);
    insertEnd(temp,tail,50);
    traverse(temp);

    insertPos(temp , tail,2,20);
    cout<<endl <<"after inserting at a position"<<endl;

    traverse(temp);
}