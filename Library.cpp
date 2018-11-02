t//
// Created by seda on 30/03/2017.
//
#include <algorithm>
#include <string>
#include <iostream>
#include "Library.h"
using namespace std;
Library::Library(){
    bookSize = 0;
}

Library::~Library(){
    delete [] this->books;
}

bool Library::isBookExist(string bookTitle) {
    transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(),::tolower);

    int i;
    for (i = 0; i < bookSize; i++)
    {
        if (books[i].getTitle().compare(bookTitle) == 0)
        {
            return true;
        }
    }
    return false;
}

void Library::addBook(string bookTitle, string publishingHouse, int publishingYear){
    Book * newBooks= new Book[bookSize+1];
    transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(),::tolower);

    if (isBookExist(bookTitle)) {
        cout << "Book already exist in the library! \n";
        return;
    }

    int i;
    for(i = 0; i < bookSize; i++) {
        string bookTitle = books[i].getTitle();
        string publisher = books[i].getPublisher();
        int year = books[i].getYear();
        int authSize = books[i].getAuthorSize();
        string * authors = books[i].getAuthors();

        newBooks[i] = Book(bookTitle, publisher, year); // TODO OLUYO MU LA BU BOYLE?

        int a;
        for( a = 0; a < authSize; a++)
        {
            newBooks[i].addAuthor(authors[a]);
        }
    }
    newBooks[bookSize] = Book(bookTitle,publishingHouse,publishingYear);

    if (bookSize!=0)
        delete [] books;

    this->bookSize++;
    this->books = newBooks;
}

void Library::removeBook(string bookTitle) {
    transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(),::tolower);

    if (!isBookExist(bookTitle))
    {
        cout << "Book doesn't exist in the library! \n";
        return;
    }

    if (bookSize != 0) {
        Book *newBooks = new Book[bookSize - 1];
        int a = 0;
        int i;

        for (i = 0; i < bookSize; i++) {
            if (books[i].getTitle().compare(bookTitle) != 0) {
                string bookTitle = books[i].getTitle();
                string publisher = books[i].getPublisher();
                int year = books[i].getYear();
                int authSize = books[i].getAuthorSize();
                string *authors = books[i].getAuthors();

                newBooks[a] = Book(bookTitle, publisher, year); // TODO OLUYO MU LA BU BOYLE?

                int j;
                for (j = 0; j < authSize; j++)
                {
                    newBooks[a].addAuthor(authors[j]);
                }
                a++;
            }
        }

        delete[] books;

        this->bookSize--;
        this->books = newBooks;
    }
}

void Library::addCoauthor(string bookTitle, string coauthorName){
    transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(),::tolower);

    bool entered = false;
    int i;

    for (i = 0; i < this->bookSize; i++)
    {
        if (books[i].getTitle().compare(bookTitle) == 0)
        {
            entered = true;
            books[i].addAuthor(coauthorName);
        }
    }

    if (!entered)
    {
        cout << "There is no such book!\n";
    }

}

void Library::removeCoauthor(string bookTitle, string coauthorName){
    transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(),::tolower);

    bool entered = false;
    int i;

    for (i = 0; i < this->bookSize; i++)
    {
        if (books[i].getTitle().compare(bookTitle) == 0)
        {
            entered = true;
            books[i].removeAuthor(coauthorName);
        }
    }

    if (!entered)
    {
        cout << "There is no such book!\n";
    }
}

void Library::displayAllBooks(){
    int i;
    if (bookSize==0)
    {
        cout<< "--EMPTY--"<<endl;
    }

    for (i = 0; i < bookSize; i++)
    {
        cout << books[i].getTitle() << ", " << books[i].getYear() << "\n";
    }

}

void Library::displayBook(string bookTitle){
    transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(),::tolower);
    bool printed = false;
    int i;
    for (i=0;i < bookSize; i++)
    {
        if (0 == bookTitle.compare(books[i].getTitle()))
        {
            books[i].printInfo();
            printed = true;
        }
    }

    if(!printed)
    {
        cout << "There is no such book! \n";
    }
}

void Library::displayAuthor(string authorName){
    bool entered = false;
    int i;
    for (i = 0; i < bookSize; i++)
    {
        if(books[i].isAuthorExist(authorName))
        {
            if (!entered)
                cout << authorName << "\n";

            cout << books[i].getTitle() << ", " << books[i].getYear() << "\n";

            entered = true;
        }
    }

    if(!entered)
    {
        cout << "--EMPTY--\n";
    }

}
