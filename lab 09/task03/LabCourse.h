#ifndef TASK_03_LABCOURSE_H
#define TASK_03_LABCOURSE_H

#include"task03Course.h"
#include<string>

class LabCourse :public Course{
private:
    double labWorkScore;
    double projectScore;
public:
    LabCourse(std::string code, int credits, double labWork, double project);
    void displayInfo()override;
    void calculateGrades()override;
};

#endif
