#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
void insertEnd(Node *&head,Node * &tail ,int d)
{
    Node *newNode  = new Node(d);
    if(tail == NULL)
    {
        head = tail =newNode;
    }
    else
    {
        tail->next  = newNode;
        tail =newNode;
    }
}
Node *rotate(Node *&head ,int k)
{
    if(head == NULL || k ==0)
    {
        return head;
    }
    Node *temp = head;
    int n =1;
    while(temp->next!=NULL)
    {
        temp = temp->next;
        n++;
    }

    k = k%n;
    if(k == 0)return head;
    temp->next = head;

    temp = head;

    for (int i = 1; i < k; i++)
    { 
        temp = temp->next;
    }
    Node * newNode = temp->next;
    temp->next  = NULL;
    return newNode;

}
void traversal(Node *head)
{
    if(head == NULL)
    {
        cout << "LL is empty"<<endl;
    }
    Node *curr = head;
    while(curr!=NULL)
    {
        cout << curr->data <<" ";
        curr = curr->next;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertEnd(head,tail,10);
    insertEnd(head,tail,20);
    insertEnd(head,tail,30);
    insertEnd(head,tail,40);
    insertEnd(head,tail,50);
    Node * rot = rotate(head,4);
    traversal(rot);
}