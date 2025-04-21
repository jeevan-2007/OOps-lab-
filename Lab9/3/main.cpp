#include<lectureCource.h>
#include<lab_c.h>

int main(){
    Cource* c1 = new Lecture_cource(85, 90, "CS101", 3);
    Cource* c2 = new Lab_cource(80, 75, "CS102", 4);
    
    c1->showDetails();
    c1->calculate_grade();
    
    c2->showDetails();
    c2->calculate_grade();
    
    delete c1;
    delete c2;
    
    return 0;
}
