#include<bits/stdc++.h>
using namespace std;

bool check = true;

class Node{
    public:
    char name[20];
    char discipline[20];
    int rollNo;
    char section;
    Node *next;

    Node(){
        next = NULL;
    }
}*head, *lastptr;


//add record of student
void add(){
    Node *p = new Node();

    cout << "Enter name of student: " << endl;
    cin >> p->name;
    
    cout << "Enter disciplin of student" << endl;
    cin >> p->discipline;

    cout << "Enter Roll Number of student" << endl;
    cin >> p->rollNo;

    cout << "Enter section of Student" << endl;
    cin >> p->section;

    // p->next = NULL;

    if(check){
        head = p;
        lastptr = p;
        check = false;
    }
    else{
        lastptr -> next = p;
        lastptr = p;
    }

    cout << endl << "Record Entered" << endl;
}


// modify student information
void modify(){
    cout << "Enter roll: ";
    int roll; cin>>roll;

    Node* previous = head;
    Node* current = head;

    if(current->rollNo != roll){
        previous = current;
        current = current->next;
    }

    cout << "Enter name of student: " << endl;
    cin >> current->name;
    
    cout << "Enter disciplin of student" << endl;
    cin >> current->discipline;

    cout << "Enter Roll Number of student" << endl;
    cin >> current->rollNo;

    cout << "Enter section of Student" << endl;
    cin >> current->section;

    cout << endl << "Record Modified for roll: " << current->rollNo << endl;
}


//search record of student
void search(){
    cout << "Enter roll of student to search" << endl;
    int roll; cin >> roll;

    Node* previous = head;
    Node* current = head;

    bool found = false;

    while(current->rollNo != roll){
        found = true;
        previous = current;
        current = current->next;
    }

    if(!found)
        cout << "No records found" << endl;
        return;

    cout << "Name: " << current->name << endl;
    cout << "Roll: " << current->rollNo << endl;
    cout << "Section: " << current->section << endl;
    cout << "Disciplin: " << current->discipline << endl;
}


//delete a students record
void del(){
    cout << "Enter roll to delete records"<< endl;
    int roll; cin>>roll;

    Node* previous = head;
    Node* current = head;

    while(current->rollNo != roll){
        previous = current;
        current = current->next;
    }

    previous->next = current->next;
    current->next = NULL;

    cout << endl << "Record deleted of roll: "<< current->rollNo << endl;
    delete current;
}


int main(){
    char x; 
    bool isTrue = true;

    while(isTrue){

        cout<<"1--->Press '1' to add New record:"<<endl;
        cout<<"2--->Press '2' to search a record:"<<endl;
        cout<<"3--->Press '3' to modify a record:"<<endl;
        cout<<"4--->Press '4' to delete a record:"<<endl;
        cout<<"5--->Press '5' to exit:"<<endl;

        cin>>x;

        switch (x)
        {
        case '1':
            add();
            break;
        case '2':
            search();
            break;
        case '3':
            modify();
            break;
        case '4':
            del();
            break;
        case '5':
            exit(0);
            break;
        default:
            cout << "Select the right option!!" << endl;
            // isTrue = false;
            continue;
    }
    }
}