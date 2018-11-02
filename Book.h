//
// Created by seda on 30/03/2017.
//

#ifndef HW1_BOOK_H
#define HW1_BOOK_H
#include <string>
using namespace std;
class Book {
public:
    Book ();
    Book (string title, string publisher, int year);
    ~Book ();
    string getTitle();
    void setTitle(string bookTitle);

    string getPublisher();
    void setPublisher(string publisherName);

    int getYear();
    void setYear(int year);

    string * getAuthors();
    void addAuthor(string author);
    void removeAuthor(string author);

    void printInfo();
    int getAuthorSize();

    bool isAuthorExist(string authorName);


private:
    string title;
    string publisher;
    int year;
    string * authors;
    int authorSize;
};
#endif //HW1_BOOK_H
