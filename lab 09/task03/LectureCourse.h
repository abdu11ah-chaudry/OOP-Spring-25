#ifndef TASK_03_LECTURE_COURSE
#define TASK_03_LECTURE_COURSE

#include"task03Course.h"
#include<string>


class LectureCourse:public Course{
private:
    double midScore;
    double finalScore;
public:
    LectureCourse(std::string code, int cred, double s1, double s2);

    void calculateGrades()override;
    void displayInfo()override;
};

#endif
