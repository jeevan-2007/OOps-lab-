#include <iostream>
#include <string>
using namespace std;
class Library{
    string Books_Lists[100]={"Ozumandias","Autobiography of Ayesh qureshi","The Alchemist","Nu fest","The Great Khali"};
    string borrowed_books[100];
    string available_books[100]= {"Ozumandias","Autobiography of Ayesh qureshi","The Alchemist","Nu fest","The Great Khali"};
    int bowrrowed_books_count=0;
    int available_books_count=5;
    int borrowed_books_index[100];
    public:
    void display_books(){
        cout<<"Books available in library are :"<<endl;
        for(int i=0;i<available_books_count;i++){
            cout<<available_books[i]<<endl;
        }
        return;
    }
    void borrow_books(string Book){
        for(int i=0;i<available_books_count;i++){
            if(available_books[i]==Book){
                borrowed_books[bowrrowed_books_count]=Book;
                borrowed_books_index[bowrrowed_books_count]=i;
                bowrrowed_books_count++;
                available_books_count--;
                for(int j=i;j<available_books_count;j++){
                    available_books[j]=available_books[j+1];
                }
                cout<<Book<<" has been borrowed"<<endl;
                break;
            }
        }
    }
    void return_books(string Book){
        for(int i=0;i<bowrrowed_books_count;i++){
            if(borrowed_books[i]==Book){
                available_books_count++;
                available_books[available_books_count-1]=Book;
                bowrrowed_books_count--;
                for(int j=i;j<bowrrowed_books_count;j++){
                    borrowed_books[j]=borrowed_books[j+1];
                }
                cout<<Book<<" has been returned"<<endl;
                break;
            }
            else if(i==bowrrowed_books_count-1){
                cout<<"Book is not borrowed"<<endl;
            }
        }
    }
    void add_books(string Book){
        string temp=available_books[available_books_count];
        available_books[available_books_count]=Book;
        available_books_count++;
    }

};
int main(){
    int choice;
    cout<<"Enter 1 to display available books"<<endl;
    cout<<"Enter 2 to borrow books"<<endl;
    cout<<"Enter 3 to return books"<<endl;
    cout<<"Enter 4 to add books"<<endl;
    cout<<"Enter 5 to exit"<<endl;
    Library L1;
    while(1){
        cin>>choice;
        cin.ignore();
        if(choice==1){
            L1.display_books();
        }
        else if(choice==2){
            string book;
            cout<<"Enter the book name to borrow"<<endl;
            getline(cin,book);
            L1.borrow_books(book);
        }
        else if(choice==3){
            string book;
            cout<<"Enter the book name to return"<<endl;
            getline(cin,book);
            L1.return_books(book);
        }
        else if(choice==4){
            string book;
            cout<<"Enter the book name to add in library"<<endl;
            getline(cin,book);
            L1.add_books(book);
        }
        else if(choice==5){
            break;
        }
    }
}