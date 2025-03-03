#include<iostream>
using namespace std;
class Account {
    protected:
    int accno;
    double balance;
    public :
    Account(int a, double b){
        accno = a;
        balance = b;
    }
    void display(){
        cout << "Account Number: " << accno << endl;
        cout << "Balance: " << balance << endl;
    }
};
class savingsacc: public Account{
    double intersert_rate;
    public:
    savingsacc(int a, double b, double ir) : Account(a, b){
        intersert_rate = ir;
    }
    void display(){
        Account::display();
        cout << "Interest Rate: " << intersert_rate << endl;
    }
};
class check_account : public Account {
    double overdraft_limit;
    public:
    check_account(int a, double b, double ol) : Account(a, b){
        overdraft_limit = ol;
    }
    void display(){
        Account::display();
        cout << "Overdraft Limit: " << overdraft_limit << endl;
    }

};
int main(){
    Account a1(123, 1000);
    a1.display();
    savingsacc sa1(124, 2000, 5);
    sa1.display();
    check_account ca1(125, 3000, 1000);
    ca1.display();
    return 0;
}