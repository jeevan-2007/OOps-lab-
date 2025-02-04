#include<iostream>
using namespace std;
struct books {
    string title;
    string author;
    int year ;
};
int main(){
    int b;
    cout<<"Enter the number of books you want to enter : "<<endl;
    cin>>b;
    books *coll_of_books=new books[b];
    for(int i=0;i<b;i++){
        cout<<"Enter the title of the book : "<<endl;
        cin>>coll_of_books[i].title;
        cout<<"Enter the author of the book : "<<endl;
        cin>>coll_of_books[i].author;
        cout<<"Enter the year of publication of the book : "<<endl;
        cin>>coll_of_books[i].year;
        }
    int y;
    cout<<"ENter the year after you want to see the books : "<<endl;
    cin >> y;
    for(int i=0;i<b;i++){
        if(coll_of_books[i].year>y){
            cout<<"The book with title "<<coll_of_books[i].title<<" and author "<<coll_of_books[i].author<<" was published after "<<y<<endl;
        }
    }
        delete [] coll_of_books;
    return 0;
}
