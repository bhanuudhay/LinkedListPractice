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

void insertBeg(Node * &head , int d)
{
    Node * newNode = new Node(d);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        newNode ->next = head;
        head = newNode;
    }
}


void insertEnd(Node * &head ,Node* &tail , int d)
{
    Node * newNode = new Node(d);
    if(tail == NULL)
    {
        head = tail = newNode;
    }
    else{
        tail->next  = newNode;
        tail = newNode;
    }
}

void insertPos(Node* &head ,int pos , int d)
{
    if(pos == 1)
    {
        cout << " Not to be inserted"<<endl;
    }
    int cnt =1;
    Node *temp = head;
    while(cnt < pos-1)
    {
        temp  = temp->next;
        cnt++;
    }
    if(temp->next == NULL)
    {
        cout << "Not to be inserted at the end "<<endl;
    }
    Node * newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
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
    Node* head =NULL ;
    Node *tail = NULL;
    insertBeg(head , 10);
    insertBeg(head , 20);
    insertBeg(head , 30);
    insertBeg(head , 40);
    traverse(head);
    cout <<endl<<"Inserting at the end"<<endl;
    insertEnd(head,tail,10);
    insertEnd(head,tail,20);
    insertEnd(head,tail,30);
    insertEnd(head,tail,40);
    traverse(head);
    


}