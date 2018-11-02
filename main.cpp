#include <iostream>
#include "Book.h"
#include "Library.h"
int main() {
/*    std::cout << "Hello, World!" << std::endl;

    Book book1("seda", "sedat&yadel", 1995);

    cout <<"created";
    book1.addAuthor("furkan");
    book1.addAuthor("eren");

    book1.printInfo();

    book1.removeAuthor("eren");

    if (book1.isAuthorExist("eren"))
        cout << "ERRORRRR!";

    if (book1.isAuthorExist("furkan"))
        cout << "furkan burda";

    book1.printInfo();
*/
    Library lib;
    lib.displayAllBooks();
    lib.addBook("book1", "sedat", 1995);
    lib.addBook("book2", "yesim", 1994);

    lib.addCoauthor("book1", "au1");
    lib.addCoauthor("book2", "au2");
    lib.addCoauthor("book1", "au3");
    lib.addBook("book3", "kadir", 2003);
   // lib.addBook("book3", "kadir", 2003);
    lib.addCoauthor("book3", "au2");

    cout << "creation is done! \n";

    lib.displayAllBooks();

    cout << "display is done! \n";

    lib.displayAuthor("au1");

    cout << "au1 is done! \n";
    lib.displayAuthor("au2");

    cout << "au2 is done! \n";

    lib.removeCoauthor("book1", "au3");
    lib.displayAuthor("au3");
    lib.displayBook("book1");
    lib.removeBook("book2");
    lib.displayAllBooks();
    lib.removeCoauthor("book4","au3");


    return 0;
}