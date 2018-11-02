
#include <string>
#include "Book.h"
using namespace std;
class Library {
public:
    Library ();
    ~Library ();
    void addBook( string bookTitle, string publishingHouse, int publishingYear );
    void removeBook( string bookTitle );
    void addCoauthor( string bookTitle, string coauthorName );
    void removeCoauthor ( string bookTitle, string coauthorName );
    void displayAllBooks();
    void displayBook( string bookTitle );
    void displayAuthor( string authorName );

private:
    bool isBookExist(string bookTitle);
    Book *books;
    int bookSize;
};
