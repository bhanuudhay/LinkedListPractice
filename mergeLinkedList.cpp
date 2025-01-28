#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

void insertEnd(Node*& head, Node*& tail, int d) {
    Node* newNode = new Node(d);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
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

Node* merge(Node*& head1, Node*& head2) {
    Node* temp = NULL;
    Node* tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            insertEnd(temp, tail, head1->data);  
            head1 = head1->next;
        } else {
            insertEnd(temp, tail, head2->data);  
            head2 = head2->next;
        }
    }

    while (head1 != NULL) {
        insertEnd(temp, tail, head1->data);
        head1 = head1->next;
    }

    while (head2 != NULL) {
        insertEnd(temp, tail, head2->data);
        head2 = head2->next;
    }

    return temp;
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;

    insertEnd(head1, tail1, 10);
    insertEnd(head1, tail1, 30);
    insertEnd(head1, tail1, 50);
    insertEnd(head1, tail1, 60);
    insertEnd(head1, tail1, 70);

    cout << "First sorted linked list:" << endl;
    traversal(head1);

    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertEnd(head2, tail2, 20);
    insertEnd(head2, tail2, 40);
    insertEnd(head2, tail2, 60);
    insertEnd(head2, tail2, 80);
    insertEnd(head2, tail2, 90);

    cout << "Second sorted linked list:" << endl;
    traversal(head2);

    cout << endl << "Merging lists:" << endl;
    Node* res = merge(head1, head2);
    traversal(res);

    return 0;
}
