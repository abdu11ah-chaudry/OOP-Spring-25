#include<iostream>
using namespace std;

class Library
{
private:
    string bookList[20];
    string borrowedBooks[20];
    string AvailableBooks[20];
    int i=0,j=0,k=0;
public:
    void addBook(string book)
    {
        bookList[i++]=book;
    }

    void lendBook(string book)
    {
        bool found=false;
        for(int p=0; p<i; p++){
            if(bookList[p]==book){
                borrowedBooks[j++]=book;
                found=true;
                break;
            }
        }
        
        if(!found){
            cout<<"This book is not available"<<endl;
            }
    }

    void returnBook(string book)
    {
        bool found=false;
        for(int p=0; p<j; p++)
        {
            if(borrowedBooks[p]==book){
                found=true;
                cout<<"Book has been returned"<<endl;

                for(int q=p;q<j-1;q++){
                    borrowedBooks[q]=borrowedBooks[q+1];
                }
                j--;
                break;
                }
        }
        
        if(!found){
            cout<<"This book was not even borrowed\n";
            }
    }

    void availableBooks(){
        k=0;
        for(int p=0; p<i; p++){
            bool found=false;
            for(int b=0; b<j; b++){
                if(bookList[p]==borrowedBooks[b]){
                    found=true;
                    break;
                    }
                }
            if(!found){
                AvailableBooks[k++]=bookList[p];
                }
            }
    }


    void displayBookList(){
        cout<<"The Whole booklist: "<<endl;
        for(int p=0;p<i;p++){
            cout<<bookList[p]<<endl;
            }
    }

    void displayBorrowedBooks(){
        cout<<"The Borrowed Books:"<<endl;
        for(int p=0; p<j; p++){
            cout<<borrowedBooks[p]<<endl;
            }
    }

    void displayAvailableBooks(){
        availableBooks();
        cout<<"The Available Books:"<<endl;
        for(int p=0; p<k; p++){
            cout<<AvailableBooks[p]<<endl;
        }
    }    

};
int main(){
    Library l1;
    l1.addBook("Deep Work");
    l1.addBook("Atomic Habbits");
    l1.addBook("The Art Of Strategy");
    l1.lendBook("Deep Work");
    l1.displayBookList();
    l1.displayBorrowedBooks();
    l1.availableBooks();
    l1.returnBook("Deep Work");
    l1.displayAvailableBooks();

    return 0;
 
}
