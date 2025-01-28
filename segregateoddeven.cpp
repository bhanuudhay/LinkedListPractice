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

void segregateLinkedList(Node *&head)
{
    if (head == NULL)
    {
        cout << "No Node exists" << endl;
        return;
    }

    Node *evenHead = NULL, *evenTail = NULL;
    Node *oddHead = NULL, *oddTail = NULL;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = temp;
                evenTail = evenHead;
            }
            else
            {
                evenTail->next = temp;
                evenTail = evenTail->next;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = temp;
                oddTail = oddHead;
            }
            else
            {
                oddTail->next = temp;
                oddTail = oddTail->next;
            }
        }
        temp = temp->next;
    }

    if (evenHead == NULL || oddHead == NULL)
    {
        return;
    }

    evenTail->next = oddHead;
    oddTail->next = NULL;

    head = evenHead;  
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
    
    insertEnd(head,tail,1);
    insertEnd(head,tail,2);
    insertEnd(head,tail,3);
    insertEnd(head,tail,4);
    insertEnd(head,tail,5);
    insertEnd(head,tail,6);
    insertEnd(head,tail,7);
    insertEnd(head,tail,8);
    segregateLinkedList(head);
    traverse(head);
    


}