#include<iostream>
using namespace std;
class Student
{
    public:
    string name;
    int marks ;
    bool grace_marks;
    Student *next;

    Student(string namee , int markss)
    {
        name  = namee;
        marks = markss;
        grace_marks = false;
        next = NULL;
    }
};

void insertStudent(Student *&head , string &nam , int mark)
{
    Student *newNode = new Student(nam,mark);

    if(head == NULL){
        head = newNode;
        return;
    }
    else{
        newNode->next = head;
        head=newNode;
    }
}

void graceGiven(Student * &head)
{
    if(head == NULL)
    {
        cout <<"Student not added"<<endl;
    }
    else
    {
        Student * temp = head;
        while(temp!=NULL)
        {
            if(temp->marks <30 && temp->grace_marks == false)
            {
                temp->marks +=15;
                temp->grace_marks = true;
                cout << " Grace marks given to  "<<temp->name<<endl;
            }
            temp = temp->next;
        }
    }

}
void displayy(Student * head)
{
    if(head == NULL)
    {
        cout<<"Student not added"<<endl;
    }
    Student *temp = head;
    while(temp!=NULL)
    {
        cout << endl <<"Name : "<<temp->name <<endl << "Marks : "<<temp->marks <<endl << "Grace Marks Given Status  " ;
        if(temp->grace_marks == true ) 
        { 
            cout <<"YES" <<endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        temp= temp->next;
    }
    cout <<endl;
}
int main()
{
    Student * head = NULL;
    int marks;
    string name;

    cout << " MENU " <<endl;
    cout << "1. Add student " <<endl;
    cout << "2. Display student data"<<endl;
    cout << "3. Provide Grace"<<endl;
    cout << "4. Exit..."<<endl;

    int choice;

    do {
        cout <<"Enter your choice  .."<<endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter name of student  ";
                cin >> name ;
                cout <<"Enter marks  ";
                cin>> marks;
                insertStudent(head , name ,marks);
                cout <<"Student successfully added"<<endl;
                break;

            case 2:
                displayy(head);
                break;

            case 3:
                cout << " Minimum passing marks is 30 "<<endl;
                cout<<endl;
                graceGiven(head);
                break;

            case 4:
                cout << " exiting "<<endl;
                break;

            default :
                cout << "Not Correct Choice"<<endl;
        }
        
    } while(choice != 4);  // Continue loop until choice is 4
}
