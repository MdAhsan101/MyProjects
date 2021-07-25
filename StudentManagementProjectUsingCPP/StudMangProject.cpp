// Student Management system using file handling in c++
#include <iostream>
#include <fstream>
#include<sstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <regex>
#include <stdio.h>
using namespace std;

class student
{
private:
    string  name, roll_no, course, address, email_id, contact_no;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};
void student::menu()
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t Add Another Student Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again.. Press any key to continue";
    }
    getch();
    goto menustart;
}
void student::insert() // add student details
{
    system("cls");
    fstream fout;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Student Details ---------------------------------------------" << endl;
    
    cin.ignore();
    cout << "\t\t\tEnter Name: ";
    getline(cin,name);
    cout << "\t\t\tEnter Roll No.: ";
    getline(cin,roll_no);
    cout << "\t\t\tEnter Course: ";
    getline(cin,course);
    cout << "\t\t\tEnter Email Id: ";
    getline(cin,email_id);
    cout << "\t\t\tEnter Contact No: ";
    getline(cin,contact_no);
    cout << "\t\t\tEnter Address: ";
    getline(cin,address);
    fout.open("studentRecord.txt", ios::app | ios::out);
    fout <<name << "/" << roll_no << "/" << course << "/" << email_id << "/" << contact_no << "/" << address << "\n";
    fout.close();
}

void student::display() // display students details
{
    system("cls");
    fstream fin;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    fin.open("studentRecord.txt", ios::in);
    
    int total=0;
    string line;
    ;
    while (getline(fin,line))
    {
        stringstream ss(line);
        cout << "\n\n\t\t\t Student No.: " << ++total << endl;
        getline(ss,name,'/');
        cout << "\t\t\t Student Name: " << name << endl;
        getline(ss,roll_no,'/');
        cout << "\t\t\t Student Roll No.: " << roll_no << endl;
        getline(ss,course,'/');
        cout << "\t\t\t Student course: " << course << endl;
        getline(ss,email_id,'/');
        cout << "\t\t\t Student Email Id.: " << email_id << endl;
        getline(ss,contact_no,'/');
        cout << "\t\t\t Student Contact No.: " << contact_no << endl;
        getline(ss,address,'/');
        cout << "\t\t\t Student Address: " << address << endl;
    }
    if (total == 0)
    {
        cout << "\n\t\t\tNo Data Is Present...";
    }
    fin.close();
}
void student::modify() // Modify Students Details
{
    system("cls");
    fstream fin, fout;
    string rollno;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    fin.open("studentRecord.txt", ios::in);
    if (!fin)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        cin.ignore();
        fout.open("record.txt", ios::app | ios::out);
        
        string line;
        while (getline(fin,line))
        {
            stringstream ss(line);
            getline(ss,name,'/');
            getline(ss,roll_no,'/');
            getline(ss,course,'/');
            getline(ss,email_id,'/');
            getline(ss,contact_no,'/');
            getline(ss,address,'/');
            if (rollno != roll_no)

                {fout << name << "/" << roll_no << "/" << course << "/" << email_id << "/" << contact_no << "/" << address << "\n";}
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                getline(cin,name);
                cout << "\t\t\tEnter Roll No.: ";
                getline(cin,roll_no);
                cout << "\t\t\tEnter Course: ";
                getline(cin,course);
                cout << "\t\t\tEnter Email Id: ";
                getline(cin,email_id);
                cout << "\t\t\tEnter Contact No.: ";
                getline(cin,contact_no);
                cout << "\t\t\tEnter Address: ";
                getline(cin,address);
                fout<< name << "/" << roll_no << "/" << course << "/" << email_id << "/" << contact_no << "/" << address << "\n";
            }
        }
        fin.close();
        fout.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
void student::search() // search data of student
{
    system("cls");
    fstream fin;
    int found = 0;
    fin.open("studentRecord.txt", ios::in);
    if (!fin)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n Enter Roll No. of Student Which You Want to Search: ";
        cin >> rollno;
        cin.ignore();

        string line;
        
        while (getline(fin,line))
        {
            stringstream ss(line);
            getline(ss,name,'/');
            getline(ss,roll_no,'/');
            getline(ss,course,'/');
            getline(ss,email_id,'/');
            getline(ss,contact_no,'/');
            getline(ss,address,'/');
            if (rollno == roll_no)
            {
                cout << "\n\t\t\t Student Name: " << name << endl;
                cout << "\t\t\t Student Roll No.: " << roll_no << endl;
                cout << "\t\t\t Student course: " << course << endl;
                cout << "\t\t\t Student Email Id.: " << email_id << endl;
                cout << "\t\t\t Student Address: " << address << endl;
                found++;
            }
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent Roll No. Not Found...";
        }
        fin.close();
    }
}
void student::deleted()
{
    system("cls");
    fstream fin, fout;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    fin.open("studentRecord.txt", ios::in);
    if (!fin)
    {
        cout << "\n\t\t\tNo Data is Present..";
        fin.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        cin.ignore();
        fout.open("record.txt", ios::app | ios::out);
        
        string line;
        while (getline(fin,line))
        {
            stringstream ss(line);
            getline(ss,name,'/');
            getline(ss,roll_no,'/');
            getline(ss,course,'/');
            getline(ss,email_id,'/');
            getline(ss,contact_no,'/');
            getline(ss,address,'/');
            if (roll != roll_no)
            {
                fout<< name << "/" << roll_no << "/" << course << "/" << email_id << "/" << contact_no << "/" << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        fin.close();
        fout.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
main()
{
    student project;
    project.menu();
    return 0;
}