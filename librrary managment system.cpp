#include <iostream>

using namespace std;
const int MAX_BOOKS=100;
int bookIds[MAX_BOOKS];
string bookName[MAX_BOOKS];
string bookAuthors[MAX_BOOKS];
bool isBorrowed[MAX_BOOKS];
int bookCount=0;

void addBook(){
 if (bookCount >=MAX_BOOKS){
    cout<<"library is full"<<'\n';
    return;
 }
cout<<"enter book ID (no spaces):";
cin>>bookIds[bookCount];
cout<<"enter book Name (no spaces):";
cin>>bookName[bookCount];
cout<<"enter book Aouther name (no spaces):";
cin>> bookAuthors[bookCount];
isBorrowed[bookCount]= false;
bookCount++;
cout<<"book added succsacfully.\n";
 }

 void displayBooks(){
    if (bookCount==0){
        cout<<"no books in the library\n";
        return;
    }
for (int i = 0; i < bookCount; i++){
cout<<"ID: "<<bookIds[i]<< ",Name: "<<bookName[i]<<",Author: "<<bookAuthors[i]<<(isBorrowed[i]?"Borrowed":"available")<<endl;
}    
 }

 void borrowBook(){
    int ID;
    cout<<"enter book ID to borrow:";
    cin>>ID;
for (int i = 0; i < bookCount; i++){
    if (bookIds[i]==ID) {
        if(isBorrowed[i]){
     cout<<"this book is already borrowed\n";   
    } else {
    isBorrowed[i]= true;
    cout<<"book borroed succsessfully\n";
    }
    return;
}
    
}

cout<<"book is not found\n";
 }

 void returnBook (){
    int ID;
    cout<<"enter ID to return";
    cin>>ID;
    for (int i = 0; i < bookCount; i++){
        if (bookIds[i] == ID){
         if(!isBorrowed[i]){
            cout<<"this book was not borrowed\n";
         } else {
            isBorrowed[i]=false;
            cout<<"book returned successfully\n"; 
         }
         return;
        }
        
    }
    cout<<"book ID is not found\n";
 }
 
 void menu(){
    int choice;
    do{
        cout<<"\n*******library management system menu*******\n";
        cout<<"1: Add new book\n";
        cout<<"2: Display all books\n";
        cout<<"3: Borrow book\n";
        cout<<"4: Return book\n";
        cout<<"5: Exit the system\n";
        cin>>choice;
        switch (choice){

        case 1 :
            addBook();
            break;
            case 2 :
            displayBooks();
            break;
            case 3 :
            borrowBook();
            break;
            case 4 :
            returnBook();
            break;
            case 5 :
            cout<<"Exiting the system\n";
            break;
        
        default:
        cout<<"invalid choice\n";
            break;
        }
    }
    while(choice!=5);
 }

int main (){
menu();
    return 0;
}