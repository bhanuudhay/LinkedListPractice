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

void deleteList(Node * &head)
{
    if(head == NULL)
    {
        cout <<"List is empty"<<endl;
        return ;
    }
    Node *curr =head;
    while(curr!=NULL)
    {
        Node *nodeToDel = curr;
        curr = curr->next;
        delete(nodeToDel);
    }
    head= NULL;
    cout <<"successfully deleted "<<endl;
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
    deleteList(head);
    cout <<endl;
    traverse(head);

}