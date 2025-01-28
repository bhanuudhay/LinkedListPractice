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
        next = NULL;
    }
};
void insertEnd(Node * &head , Node  * &tail , int d)
{
    Node * newNode = new Node(d);
    if(tail == NULL)
    {
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}
void traversal(Node * &head){
    if (head == NULL)
    {
        cout <<"linked list not exists"<<endl;
    }
    Node *temp = head;
    while(temp!=NULL)
    {
        cout <<temp->data<<" ";
        temp = temp->next;
    }
}

void rev(Node *&head,Node * &curr ,Node * &prev)
{
    if(curr==NULL)
    {
        head = prev;
        return;
    }
    Node * next = curr->next;
    rev(head,next,curr);
    curr->next = prev;
}
int main()
{
    Node * head = NULL;
    Node *tail = NULL;
    int  n =0;
    cout << "Enter n"<<endl;
    cin >> n;
    int data;
    for(int i =0; i<n;i++)
    {
        cout << "Enter data for" <<i <<"th node  " <<endl;
        cin >> data;
        insertEnd(head,tail,data);
    }
    traversal(head);
    Node * prev = NULL;
    Node * curr  = head;
    cout <<endl<<" after reversing the linked list"<<endl;
    rev(head,curr , prev);
    traversal(head);


}