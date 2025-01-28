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

Node * middle(Node *&head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    if(head ->next->next  == NULL)
    {
        return head->next;
    }

    Node * slow= head;
    Node * fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void FrontBackSplit(Node * &head)
{
    if(head == NULL)
    {
        cout << "No element is present "<<endl;
    }
    Node * mid = middle(head);
    Node * temp = NULL;
    Node * tail = NULL ;

    Node * curr  = head;

    Node * temp1 = NULL;
    Node * tail1 = NULL ;
    while(curr!=NULL)
    {
        insertEnd(temp , tail,curr->data);
        if(curr->data == mid->data)
        {
            break;
        }
        curr = curr->next;
    }
    Node *second  =curr->next;
    while(second!=NULL)
    {
        insertEnd(temp1,tail1,second->data);
        second = second->next;
    }
    traversal(temp);
    cout <<endl;
    traversal(temp1);

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
    insertEnd(head,tail,7);
    insertEnd(head,tail,8);
    insertEnd(head,tail,9);
    insertEnd(head,tail,10);
    FrontBackSplit(head);
}