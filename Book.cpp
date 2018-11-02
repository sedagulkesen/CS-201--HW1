//
// Created by seda on 30/03/2017.
//

#include "Book.h"
#include <iostream>

using namespace std;
Book::Book(){
    this->title="";
    this->publisher="";
    this->year=-1;
}
Book::Book (string title, string publisher, int year){
    this->title = title;
    this->publisher = publisher;
    this->year = year;
    this->authorSize = 0;
}
Book::~Book () {
    if (authorSize!=0)
        delete [] this->authors;
}
string Book::getTitle() {
    return this->title;
}
void Book::setTitle(string bookTitle) {
    this->title = title;
}

string Book::getPublisher() {
    return this->publisher;
}
void Book::setPublisher(string publisherName) {
    this->publisher = publisherName;
}

int Book::getYear() {
    return this->year;
}
void Book::setYear(int year) {
    this->year=year;
}

string * Book::getAuthors() {
    return this->authors;
}
void Book::addAuthor(string author) {

    if (isAuthorExist(author)) {
        cout << "The author already exist!\n";
        return;
    }
    string * newAuthors = new string[authorSize+1];

    int i;
    for(i = 0; i < authorSize; i++) {
        newAuthors[i] = authors[i];
    }

    newAuthors[authorSize] = author;
    if (authorSize!=0)
        delete [] authors;
    this->authorSize = authorSize + 1;
    this->authors = newAuthors;
}
void Book::removeAuthor(string author) {
    if (!isAuthorExist(author))
    {
        cout << "This author does not exist for the given book!\n";
        return;
    }

    string * newAuthors = new string[authorSize-1];

    int i;
    int index_new = 0;
    for(i = 0; i < authorSize; i++) {
        if (author.compare(authors[i]) != 0) {
            newAuthors[index_new] = authors[i];
            index_new++;
        }
    }

    if (authorSize!=0)
        delete [] this->authors;

    this->authorSize--;
    this->authors = newAuthors;
}

int Book::getAuthorSize(){
    return this->authorSize;
}
bool Book::isAuthorExist(string authorName){
    int i;
    for(i = 0; i < authorSize; i++){
        if(authorName.compare( authors[i]) == 0)
            return true;
    }

    return false;
}

void Book::printInfo() {
    cout << this->title << ", " << this->publisher << ", " << this->year << "\n";

    int i;
    for (i = 0; i < authorSize; i++)
    {
        cout << authors[i] << "\n";
    }
}