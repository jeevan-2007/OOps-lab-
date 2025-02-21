#include <iostream>
#include <string>

using namespace std;

class employee {
    string name;
    string designation;
    int projectsassignedto;

public:
    employee() : projectsassignedto(0) {}

    void setname(string name) {
        this->name = name;
    }

    void setdesignation(string desig) {
        this->designation = desig;
    }

    void projts(int a) {
        projectsassignedto += a;
    }

    void show_details() {
        cout << "Employee Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Projects Assigned: " << projectsassignedto << endl;
    }
};

class project {
    string title;
    int deadline;
    employee *employees_assigned;
    int employeescap;
    int currnt_emp = 0;

public:
    project() : employees_assigned(nullptr), employeescap(0) {}

    void set_title(string title) {
        this->title = title;
    }

    void setdeadline(int day) {
        deadline = day;
    }

    void set_employess_capacity(int cap) {
        employeescap = cap;
    }

    void assignmemory() {
        employees_assigned = new employee[employeescap];
    }

    void add_employees(employee s) {
        if (currnt_emp < employeescap) {
            employees_assigned[currnt_emp] = s;
            currnt_emp++;
            cout << "Employee added to the project: " << s.name << endl;
            s.projts(1);
        } else {
            cout << "Capacity is full. Cannot add more employees." << endl;
        }
    }

    void show_project_details() {
        cout << "Project Title: " << title << endl;
        cout << "Deadline: " << deadline << endl;
        cout << "Assigned Employees: " << endl;
        for (int i = 0; i < currnt_emp; i++) {
            employees_assigned[i].show_details();
        }
    }

    ~project() {
        delete[] employees_assigned;
    }
};

int main() {
    employee emp1, emp2, emp3;
    emp1.setname("John Doe");
    emp1.setdesignation("Software Engineer");
    emp2.setname("Alice Smith");
    emp2.setdesignation("Project Manager");
    emp3.setname("Bob Brown");
    emp3.setdesignation("Data Scientist");

    project proj;
    proj.set_title("Project Alpha");
    proj.setdeadline(30);
    proj.set_employess_capacity(3);
    proj.assignmemory();

    proj.add_employees(emp1);
    proj.add_employees(emp2);
    proj.add_employees(emp3);
    proj.add_employees(emp1);

    proj.show_project_details();

    return 0;
}
