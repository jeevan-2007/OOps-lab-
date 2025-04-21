#ifndef LECTURECOURCE_H
#define LECTURECOURCE_H

#include<cource.h>

class Lecture_cource:public Cource{
    private:
    float assignment_marks, exam_marks;
public :
    Lecture_cource(float assignment_marks,float exam_marks, string code, int credit);
    void calculate_grade();
    void shoedDetails();    
};
#endif