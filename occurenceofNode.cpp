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

void countOccurence(Node * &head , int d)
{
    if(head == NULL)
    {
        cout << "No existing node"<<endl;
    }
    int count =0;
    Node *temp = head;
    while(temp !=NULL)
    {
        if(temp->data == d)
        {
            count++;
        }
        temp = temp->next;
    }
    cout << count <<endl;
}
int main()
{
    Node* head =NULL ;
    insertBeg(head , 10);
    insertBeg(head , 20);
    insertBeg(head , 30);
    insertBeg(head , 40);
    insertBeg(head , 30);
    insertBeg(head , 50);
    insertBeg(head , 30);
    countOccurence(head , 30);

    
}