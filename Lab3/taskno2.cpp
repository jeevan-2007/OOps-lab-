#include <iostream>
using namespace std;
class Fitness_tracketr{
    string username;
    int Daily_steps_Goal;
    int Daily_steps_taken;
    int Calories_burned;
    public:
    void set_username(string name){
        username = name;
    }
    void set_Daily_steps_Goal(int goal){
        Daily_steps_Goal = goal;
    }
    void set_Daily_steps_taken(int steps){
        Daily_steps_taken = steps;
    }
    int Calories_Burned(int daily_steps_taken){
        Calories_burned = Daily_steps_taken*0.05;
        return Calories_burned;
    }
    void display_progress(){
        cout<<"Username: "<<username<<endl;
        cout<<"Daily Steps Goal: "<<Daily_steps_Goal<<endl;
        cout<<"Daily Steps Taken: "<<Daily_steps_taken<<endl;
        cout<<"Calories Burned: "<<Calories_burned<<endl;
        cout<<"Progress: "<<(Daily_steps_taken*100)/Daily_steps_Goal<<"%"<<endl;
    }
};
int main(){
    Fitness_tracketr user1;
    string name;
    int goal,steps,calories;
    cout<<"Enter the username ,Steps_Goal ,Steps_Completed ,Calories burned :  ";
    cin>>name>>goal>>steps>>calories;
    user1.set_username(name);
    user1.set_Daily_steps_Goal(goal);
    user1.set_Daily_steps_taken(steps);
    cout<<"Calories burned: "<<user1.Calories_Burned(steps)<<endl;
    user1.display_progress();
    return 0;
}