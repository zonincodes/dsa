#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <string.h>
using namespace std;

class Patron; // foward declaration

class Book{

public:
    Book(){
        patron = 0;
    }

    bool operator == (const Book &bk) const {
        return strcmp(title, bk.title) == 0;
    }

private:
    char *title;
    Patron *patron;
    ostream &printBook(ostream &) const;
    friend ostream &operator << (ostream &out, const Book &bk){
        return bk.printBook(out);
    }
    friend Patron;
    friend class CheckedOutBook;
    friend void includeBook();
    friend void checkOutBook();
    friend void returnBook();
}; // book class end


//  class Author

class Author{
public: 
    Author(){}

    bool operator == (const Author &ar) const {
        return strcmp(name, ar.name) == 0;
    }

private:
    char *name;
    list <Book> books;
    ostream &printOuthor (ostream &) const ;
    
    friend ostream &operator << (ostream &out, const Author &ar){
        return ar.printOuthor(out);

    }

    friend void includeBook();
    friend void checkOutBook();
    friend void returnBook();
    friend class CheckedOutBook;
    friend Patron;

}; // Class Author end

// datatype checkedoutBook start
class CheckedOutBook{
public:
    CheckedOutBook(list<Author>::iterator ar, list<Book>::iterator bk){
        author = ar;
        book = bk;
    }

    bool operator== (const CheckedOutBook &bk) const {
        return strcmp(author -> name, bk.author -> name) == 0 && strcmp(book -> title, bk.book -> title) == 0;
    }

private:
    list<Author>::iterator author;
    list<Book>::iterator book;
    friend void checkOutBook();
    friend void returnBook();
    friend Patron;

}; // datatype checkedoutBook end

//  Patron class
class Patron{
public: 
    Patron(){

    }

    bool operator==(const Patron &pn) const {
        return strcmp(name, pn.name) == 0;
    }

private:
    char *name;
    list<CheckedOutBook> books;
    ostream &printPatron(ostream &) const;
    friend ostream &operator<< (ostream &out, const Patron &pn){
        return pn.printPatron(out);
    }

    friend void checkOutBook();
    friend void returnBook();
    friend Book;
}; // end of patron class

