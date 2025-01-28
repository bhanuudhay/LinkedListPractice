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
void conatenateList(Node *&head , Node *&head2)
{
    if(head == NULL)
    {
        traversal(head2);
    }
    if(head2 == NULL)
    {
        traversal(head);
    }
    Node *curr = head;
    Node * tail = head;
    while(tail!=NULL && tail->next!=NULL)
    {
        tail = tail->next;
    }
    tail->next = head2;
    while(tail!=NULL)
    {
        tail =tail->next;
    }
    traversal(curr);
}
int main()
{
    int  n = 0 , m =0 , d =0 , d1 =0;
    Node *head = NULL;
    Node *tail = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;
    cout <<endl;    
    cout <<endl;    
    cout << " ----------------- HELLO WELCOME TO MY SOFTWARE----------------" <<endl;
    cout << " Enter how many element you want in first list : ";
    cin >>n;
    for(int i = 0 ; i<n;i++)
    {
            cout <<"Enter data you want to insert in " << i+1 << " th Node : ";
            cin >> d;
            insertEnd(head,tail,d);
    }
    cout <<endl;
    cout <<" Enter how many element you want in secind list : "<<endl;
    cin>> m;
    for(int j = 0 ; j<m;j++)
    {
            cout <<"Enter data you want to insert in " << j+1 << " th Node : ";
            cin >> d1;
            insertEnd(head2,tail2,d1);
    }
    cout << endl;
    cout << " first list :  " ;
    traversal(head);
    cout <<endl;
    cout << " second list :  ";
    traversal(head2);
    cout <<endl;
    cout << "concatenated list : " <<endl;
    conatenateList(head,head2);
    



}