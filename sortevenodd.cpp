#include<iostream>
using namespace std;
class Node 
{
    public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next =NULL;
    }
};

void insertEnd(Node * &head , Node* &tail ,int d)
{
    Node * newNode = new Node(d);
    if(tail ==NULL)
    {
        head =tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void traversal(Node*& head) {
    if (head == NULL) {
        cout << "Linked list does not exist" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node * evenNodes(Node* &head )
{
    if(head == NULL)
    {
        cout <<  "NO node is there "<<endl;
        return NULL;
    }
    Node *temp  = NULL;
    Node *tail =  NULL;
    Node *curr = head;

    int index =0 ;
    while(curr!=NULL)
    {
        if(index%2 == 0)
        {
            insertEnd(temp,tail,curr->data);
        }
        curr = curr->next;
        index++;
    }
    return temp;
}

Node * oddNode(Node * &head)
{
    if(head == NULL)
    {
        cout << "No element present"<<endl;
        return NULL;
    }
    int index =0;
    Node* temp = NULL;
    Node* curr = head;
    Node* tail = NULL;

    while(curr!=NULL)
    {
        if(index%2!=0)
        {
            insertEnd(temp,tail,curr->data);
        }
        curr = curr->next;
        index++;
    }
    return temp;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;



    insertEnd(head,tail,2);
    insertEnd(head,tail,3);
    insertEnd(head,tail,4);
    insertEnd(head,tail,5);
    insertEnd(head,tail,6);
    traversal(head);

    Node *  result = evenNodes(head);

    traversal(result);

    cout<< "even nodes are"<<endl;

    Node * oddd = oddNode(head);

    cout << "odd nodes are "<<endl;

    traversal(oddd);

}