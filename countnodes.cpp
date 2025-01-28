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

int countNode(Node *&head )
{
    if(head == NULL)
    {
        return 0;
    }
    int count = 0;
    Node *temp = head;
    while(temp!=NULL)
    {
        count ++;
        temp = temp->next;
    }
    return count;
}
int main()
{
    Node* head =NULL ;
    insertBeg(head , 10);
    insertBeg(head , 20);
    insertBeg(head , 30);
    insertBeg(head , 40);
    insertBeg(head , 50);
    int n = countNode(head);
    cout << n <<endl;
}