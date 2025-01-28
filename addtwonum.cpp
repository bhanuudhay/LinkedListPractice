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

Node * addLl(Node *&head , Node  *&head1)
{
    if (!head) return head1;
    if (!head1) return head;
    Node *tail = head;
    Node * tail1 = head1;
    while(tail!=NULL)
    {
        tail = tail->next;
    }
    while(tail1!=NULL)
    {
        tail1 = tail1->next;
    }
    int len1 = countNode(head);
    int len2 = countNode(head1);
    int sum =0;
    int carry = 0;
    Node *temp = NULL;
    Node *prev = NULL;
    while(len1>=1  && len2>=1)
    {
        carry = sum%10;
        sum= tail->data + tail1->data + carry;
        insertEnd(temp,prev,sum);
    }
    return temp;
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
    insertEnd(head,tail,4);
    insertEnd(head,tail,5);

    Node *head1 = NULL;
    Node *tail1 = NULL;

    insertEnd(head,tail,3);
    insertEnd(head,tail,4);
    insertEnd(head,tail,5);

    Node * summ = addLl(head,head1);
    traversal(summ);
}
