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

void removeDuplicate(Node *head )
{
   if(head == NULL)
   {
    cout << "no element presetn"<<endl;
   }
   Node * curr = head;
   while(curr!=NULL && curr->next!=NULL)
   {
        if(curr->data == curr->next->data)
        {
            Node * nodeDel = curr->next;
            curr->next =curr->next->next;
            delete(nodeDel);
        }
        else
        {
            curr= curr->next;
        }
   }

}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertEnd(head,tail,1);
    insertEnd(head,tail,2);
    insertEnd(head,tail,3);
    insertEnd(head,tail,4);
    insertEnd(head,tail,4);
    insertEnd(head,tail,5);
    insertEnd(head,tail,5);
    insertEnd(head,tail,6);
    removeDuplicate(head);
    traversal(head);
     

}