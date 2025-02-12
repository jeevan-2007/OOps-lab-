#include<iostream>
using namespace std;
class wallet{
    private:
    string owner_name;
    int totalbalance;
    int transaction_added[100],transaction_spent[100];
    int transaction_count_add=0;
    int transaction_count_spent=0;

    public:
    wallet(){
        totalbalance=0;
    }
    void display_total_bal(){
        cout<<totalbalance<<endl;
    }
    void add_bal(int add_balance){
        totalbalance+=add_balance;
        transaction_added[transaction_count_add]=add_balance;
        transaction_count_add++;
    }
    void spend_money(int amount){
        totalbalance-=amount;
        transaction_spent[transaction_count_spent]=amount;
        transaction_count_spent++;
    }
    void display_transation(){
        cout<<"Transcation that are added :"<<endl;
        for(int i=0;i<transaction_count_add;i++){
            cout<<transaction_added[i]<<" ,";
        }
        cout<<"Transcation that are spent :"<<endl;
            for(int i=0;i<transaction_count_spent;i++){
                cout<<transaction_spent[i]<<" ,";
            }
        }
};
int main(){
    wallet A1;
    while (1){
    int choice;
    cout<<"Enter 1 to add money"<<endl;
    cout<<"Enter 2 to spend money"<<endl;
    cout<<"Enter 3 to display total balance"<<endl;
    cout<<"Enter 4 to display transaction"<<endl;
    cout<<"Enter 5 to exit"<<endl;
    cin>>choice;
    if (choice == 1){
        int adde_bal;
        cout<<"Enter the amount to add in wallet"<<endl;
        cin>>adde_bal;
        A1.add_bal(adde_bal);
    }
    else if (choice == 2){
        int spend_bal;
        cout<<"Enter the amount to spend from wallet"<<endl;
        cin>>spend_bal;
        A1.spend_money(spend_bal);
    }
    else if (choice == 3){
        A1.display_total_bal();
    }
    else if (choice == 4){
        A1.display_transation();
    }
    else if (choice == 5){
        exit(0);
    }
    }
    return 0;}
