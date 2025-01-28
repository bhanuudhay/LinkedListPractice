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
void insertEnd(Node* &head , Node* &tail , int d)
{
    Node  *newNode = new Node(d);
    if(tail == NULL)
    {
        head =tail =newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void traverse(Node *head)
{
    if(head == NULL)
    {
        cout <<"NO element present"<<endl;
    }
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->data<< " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertEnd(head , tail , 10);
    insertEnd(head , tail , 20);
    insertEnd(head , tail , 30);
    insertEnd(head , tail , 40);
    insertEnd(head , tail , 50);

    traverse(head);

    cout <<endl<<"after reversing"<<endl;
    if(head==NULL && head->next ==NULL)
    {
        return head->data;
    }

    Node * prev = NULL;
    Node * ford = NULL;
    Node * curr =head;
    while(curr!=NULL)
    {
        ford = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ford;
    }
    traverse(prev);
    


}