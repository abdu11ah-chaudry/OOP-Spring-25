#include<iostream>
#include"task03LectureCourse.h"
#include"task03LabCourse.h"
using namespace std;

int main(){

    LectureCourse lecture("CS101",3,75.0,85.0);
    LabCourse lab("CS102L",1,90.0,80.0);

    Course* course1=&lecture;
    Course* course2=&lab;

    course1->displayInfo();
    course1->calculateGrades();

    course2->displayInfo();
    course2->calculateGrades();
    
    return 0;
}
