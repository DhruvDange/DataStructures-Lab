#ifndef FOREHEAD_H
#define FOREHEAD_H

    typedef struct Student{
    char name[20];
    int usn;
    struct Student * next;
    }Student;

    Student *head;

    int sCount;

    Student * createStudentNode(Student * ptr);
    Student * searchStudent(int usnToSearch);
    void addStart();
    void addEnd();
    void addAny();
    void deleteStudent();
    void display();
    void reverse();
    
#endif





