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

void deleteNode(Node * &head )
{
    if(head == NULL){
        cout << "Nothing to delete"<<endl;
        return;
    }
    else
    {
        Node *temp = head;
        head = temp->next;
        delete(temp);
        cout<<"Node  successfully deleted"<<endl;
    }

}

void deletePos(Node* &head, Node* &tail, int pos)
{
    if (head == NULL)
    {
        cout << "No Node present" << endl;
        return;
    }

    if (pos == 1)  
    {
        deleteNode(head);
    }

    Node *temp = head;
    int cnt = 1;


    while (temp != NULL && cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Deleting out of bound" << endl;
        return;
    }

    if (temp->next->next == NULL)
    {
        tail = temp;  
    }

    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete (nodeToDelete);
    cout << "Node successfully deleted" << endl;
}

void deleteEnd(Node * &head)
{
    if(head == NULL)
    {
        cout<< "Nothing to delete"<<endl;
    }
    else if(head->next ==NULL)
    {
        delete (head);
        head = NULL;
        cout <<"Node successfully deleted"<<endl;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL && temp->next->next !=NULL)
        {
            temp  = temp->next;
        }
        Node * nodeToDelete = temp->next->next;
        temp->next = NULL;
        delete (nodeToDelete);
    }
}
int main()
{
    Node* head =NULL ;
    insertBeg(head , 10);
    insertBeg(head , 20);
    insertBeg(head , 30);
    insertBeg(head , 40);
    insertBeg(head , 30);
    deleteEnd(head);

    traverse(head);
    
}