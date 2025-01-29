//Input: num1 = 4 - > 5, num2 = 3 -> 4 -> 5
//Output:  3 -> 9 -> 0
#include<iostream>
using namespace std;
class Node
{
    public:
    Node *next;
    int data;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertNode(Node * &head, Node * &tail , int d)
{
    Node * newNode = new Node(d);
    if(tail == NULL)
    {
        head = tail = newNode;
        return;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

Node * rev(Node * &head)
{
    if(head  == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    Node * prev = NULL;
    Node * ford = NULL;
    while(curr!=NULL)
    {
        ford = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ford;
    }
    return prev;
}

Node *  addtwo(Node * &num1 , Node * &num2)
{
    Node *temp = NULL;
    Node *tail = NULL;
    int carry =0;
    while(num1!=NULL || num2!=NULL || carry != 0)
    {
        int val1 = 0;
        if(num1!=NULL)
            {
                val1 = num1->data;
            }
        int val2 = 0;
        if(num2!=NULL)
            {
                val2 = num2->data;
            } 
        int sum  = carry +  val1 + val2;
        int digit = sum%10;
        insertNode(temp,tail,digit);
        carry = sum/10;
        if(num1!=NULL)
        {
            num1 = num1->next;
        }
        if(num2!=NULL)
        {
            num2 = num2->next;
        }
    }
    return temp;
}
void traversal(Node *head)
{
    if(head == NULL)
    {
        cout <<"No element";
    }
    Node *temp = head;
    while(temp!=NULL)
    {
        cout << temp->data <<" ";
        temp = temp->next;
    }
}
int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;
    insertNode(head1,tail1 ,0);
    insertNode(head1,tail1 ,0);
    insertNode(head1,tail1 ,6);
    insertNode(head1,tail1 ,3);

    Node *head2 = NULL;
    Node *tail2 = NULL;

    insertNode(head2, tail2,0);
    insertNode(head2, tail2,7);
    
    // reverse both list

    Node * num1  = rev(head1);
    Node *num2  = rev(head2);

    Node * ans = addtwo(num1 , num2);

    ans  = rev(ans);
    while((ans->data) == 0 && ans->next!=NULL)
    {
        Node *nodeto =ans;
        ans = ans->next;
        delete(nodeto);
    } 
    
    traversal(ans);
}