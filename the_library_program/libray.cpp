#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <string.h>
using namespace std;

class Patron; // foward declaration

class Book
{

public:
    Book()
    {
        patron = 0;
    }

    bool operator==(const Book &bk) const
    {
        return strcmp(title, bk.title) == 0;
    }

private:
    char *title;
    Patron *patron;
    ostream &printBook(ostream &) const;
    friend ostream &operator<<(ostream &out, const Book &bk)
    {
        return bk.printBook(out);
    }
    friend Patron;
    friend class CheckedOutBook;
    friend void includeBook();
    friend void checkOutBook();
    friend void returnBook();
}; // book class end

//  class Author

class Author
{
public:
    Author() {}

    bool operator==(const Author &ar) const
    {
        return strcmp(name, ar.name) == 0;
    }

private:
    char *name;
    list<Book> books;
    ostream &printAuthor(ostream &) const;

    friend ostream &operator<<(ostream &out, const Author &ar)
    {
        return ar.printAuthor(out);
    }

    friend void includeBook();
    friend void checkOutBook();
    friend void returnBook();
    friend class CheckedOutBook;
    friend Patron;

}; // Class Author end

// datatype checkedoutBook start
class CheckedOutBook
{
public:
    CheckedOutBook(list<Author>::iterator ar, list<Book>::iterator bk)
    {
        author = ar;
        book = bk;
    }

    bool operator==(const CheckedOutBook &bk) const
    {
        return strcmp(author->name, bk.author->name) == 0 && strcmp(book->title, bk.book->title) == 0;
    }

private:
    list<Author>::iterator author;
    list<Book>::iterator book;
    friend void checkOutBook();
    friend void returnBook();
    friend Patron;

}; // datatype checkedoutBook end

//  Patron class
class Patron
{
public:
    Patron()
    {
    }

    bool operator==(const Patron &pn) const
    {
        return strcmp(name, pn.name) == 0;
    }

private:
    char *name;
    list<CheckedOutBook> books;
    ostream &printPatron(ostream &) const;
    friend ostream &operator<<(ostream &out, const Patron &pn)
    {
        return pn.printPatron(out);
    }

    friend void checkOutBook();
    friend void returnBook();
    friend Book;
}; // end of patron class

list<Author> catalog['Z' + 1];
list<Patron> peaople['Z' + 1];

ostream &Author::printAuthor(ostream &out) const
{
    out << name << endl;
    list<Book>::const_iterator ref = books.begin();
    for (; ref != books.end(); ref++)
        out << *ref; // overloaded <<
    return out;
}

ostream &Patron::printPatron(ostream &out) const
{
    out << name;
    if (!books.empty())
    {
        out << " Hass the following books: \n";
        list<CheckedOutBook>::const_iterator bk = books.begin();
        for (; bk != books.end(); bk++)
        {
            out << "    * " << bk->author->name << ", " << bk->book->title << endl;
        }
    }
    else
        out << "has no books \n";
    return out;
}

template <class T>
ostream &operator<<(ostream &out, const list<T> &lst)
{
    for (list<T>::const_iterator ref = lst.begin; ref != lst.end(); ref++)
        out << *ref; // overloaded <<
    return out;
}

char *getString(char *msg){
    char s[82], i, *destin;
    cout << msg;
    cin.get(s, 80);
    while (cin.get(s[81]) && s[81] != '\n'); // discard overflowing
    destin = new char[strlen(s) + 1];
    for(i = 0; destin[i] == toupper(s[i]); i++);
    return destin;
}

void includeBook() {
    Author newAuthor;
    Book newBook;
    newAuthor.name = getString("Enter author's name: ");
    newBook.title = getString("Enter the title of the book: ");
    list<Author>::iterator oldAuthor = find(catalog[newAuthor.name[0]].begin(),
        catalog[newAuthor.name[0]].end(), newAuthor);
    if(oldAuthor == catalog[newAuthor.name[0]].end()){
        newAuthor.books.push_front(newBook);
        catalog[newAuthor.name[0]].push_front(newAuthor);
    }
    else (*oldAuthor).books.push_front(newBook);
}