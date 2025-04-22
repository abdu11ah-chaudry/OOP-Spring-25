#include"task03LectureCourse.h"
#include<iostream>
using namespace std;

LectureCourse::LectureCourse(string code, int credits, double midterm, double finalExam):Course(code, credits),
    midScore(midterm),finalScore(finalExam){}

void LectureCourse::displayInfo(){
    cout<<"Lecture Course: "<<CourseCode<<" | Credits: "<<credits<<endl;
}

void LectureCourse::calculateGrades(){
    cout<<"Grade in Course: "<<CourseCode<<" = "<<(midScore * 0.4 + finalScore * 0.6)<<endl;
}
