#include<string>
#ifndef TASK_03_COURSE_H
#define TASK_03_COURSE_H

class Course{
protected:
    std::string CourseCode;
    int credits;
public:
    Course(std::string code, int crd):CourseCode(code),credits(crd){}

    virtual void calculateGrades()=0;
    virtual void displayInfo()=0;
    virtual ~Course(){}
};

#endif
