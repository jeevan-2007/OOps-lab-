/*Consider a scenario in a small banking system where security and authorized access to account entities is crucial. You are required to implement the most important entities like account number and balance to ensure safe encapsulation. To manage and perform operations on these accounts, such as deposits and transfers, a class Manager will be introduced with appropriate access control. This task will assist students in the understanding of encapsulation and digitally secured interaction without violating encapsulation principles. Additionally, to perform inter-account transactions, a standalone friend function named transferFunds() will be created to move money between accounts securely.

Requirements:

Define a class Account with private members for the account number and balance.

Use the friend class declaration so that a class Manager can access and update the account’s private members.

Implement a function transferFunds() to facilitate the transfer of funds between two Accounts, ensuring sufficient balance exists.

Implement another function in the Manager class to display account details and update balances after transactions.

Write a main function to create multiple accounts and a Manager object, transferring funds, and displaying the updated account information.
*/
#include <iostream>
#include <string>
using namespace std;
class Account{
    private:
        string accountNumber;
        double balance;
    public:
        Account(string accNum, double bal) : accountNumber(accNum), balance(bal) {}
        friend class Manager; 
        friend void transferFunds(Account &from, Account &to, double amount);
        void display() const {
            cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
        }   
};
class Manager{
    public:
        
        void displayAccountDetails(Account &acc) {
            cout << "Account Number: " << acc.accountNumber << ", Balance: $" << acc.balance << endl;
        }
        void updateBalance(Account &acc, double amount) {
            acc.balance += amount;
        }
};
    void transferFunds(Account &from, Account &to, double amount) {
        if (from.balance >= amount) {
            from.balance -= amount;
            to.balance += amount;
            cout << "Transfer successful! $" << amount << " transferred from " << from.accountNumber << " to " << to.accountNumber << endl;
        } else {
            cout << "Transfer failed! Insufficient balance in account " << from.accountNumber << endl;
        }
    }
int main(){
    Account acc1("123456", 1000.0);
    Account acc2("654321", 500.0);
    Manager manager;

    cout << "Before Transfer:" << endl;
    manager.displayAccountDetails(acc1);
    manager.displayAccountDetails(acc2);
    transferFunds(acc1, acc2, 200.0);

    cout << "After Transfer:" << endl;
    manager.displayAccountDetails(acc1);
    manager.displayAccountDetails(acc2);
    return 0;
}