#include"task03LabCourse.h"
#include<iostream>
using namespace std;

LabCourse::LabCourse(string code, int credits, double lScore, double pScore):Course(code, credits),
    labWorkScore(lScore),projectScore(pScore){}

void LabCourse::displayInfo(){
    cout<<"Lab Course: "<<CourseCode<<" | Credits: "<<credits<<endl;
}

void LabCourse::calculateGrades(){
    cout<<"Grade in Course: "<<CourseCode<<" = "<<(labWorkScore * 0.4 + projectScore * 0.6)<<endl;
}
