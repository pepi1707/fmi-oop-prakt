#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 101;
const int MAX_BOOKS = 1001;
const double EPS = 1e-7;

struct Book
{
    char name[MAX_SIZE];
    char author[MAX_SIZE];
    char isbn[MAX_SIZE];
    char genre[MAX_SIZE];
    double cost;
};

struct Bookstore
{
    int numBooks;
    Book books[MAX_BOOKS];
};

void initializeBookstore(Bookstore &store, const char *fileName)
{
    ifstream file(fileName);
    file>>store.numBooks;
    file.ignore();
    char nothing[2];
    for(int i = 0; i < store.numBooks ; i++)
    {
        file.getline(store.books[i].name, MAX_SIZE - 1);
        file.getline(store.books[i].author, MAX_SIZE - 1);
        file.getline(store.books[i].isbn, MAX_SIZE - 1);
        file.getline(store.books[i].genre, MAX_SIZE - 1);
        file>>store.books[i].cost;
        file.ignore();
        if(i + 1 < store.numBooks)
            file.getline(nothing, 1);
    }
    file.close();
}

void printBookstore(const Bookstore &store)
{
    cout << store.numBooks << endl;
    for(int i = 0; i < store.numBooks ; i++)
    {
        cout << store.books[i].name << endl;
        cout << store.books[i].author << endl;
        cout << store.books[i].isbn << endl;
        cout << store.books[i].genre << endl;
        cout << store.books[i].cost << endl;
        cout << endl;
    }
}

bool hasBookWithISBN(const Bookstore &store, const char *isbn)
{
    for(int i = 0 ; i < store.numBooks; i++)
    {
        if(!strcmp(store.books[i].isbn,isbn))
            return true;
    }
    return false;
}

void getAllBooksByAuthorName(const Bookstore &store, const char *authorName, const char *outputFileName)
{
    ofstream out(outputFileName);
    int counter = 0;
    for(int i = 0 ; i < store.numBooks; i++)
    {
        if(!strcmp(store.books[i].author, authorName))
            counter++;
    }

    out << counter << "\n";
    for(int i = 0; i < store.numBooks; i++)
    {
        if(!strcmp(store.books[i].author, authorName))
        {
            out << store.books[i].name << "\n";
            counter--;
            if(counter)
                out << "\n";
        }
    }

    out.close();
}

void getAllBooksByGenre(const Bookstore &store, const char *genre, const char *outputFileName)
{
    ofstream out(outputFileName);
    int counter = 0;
    for(int i = 0 ; i < store.numBooks; i++)
    {
        if(!strcmp(store.books[i].genre, genre))
            counter++;
    }

    out << counter << "\n";
    for(int i = 0; i < store.numBooks; i++)
    {
        if(!strcmp(store.books[i].genre, genre))
        {
            out << store.books[i].name << "\n";
            counter--;
            if(counter)
                out << "\n";
        }
    }

    out.close();
}

void getAllBooksCheaperThan(const Bookstore &store, const double price, const char *outputFileName)
{
    ofstream out(outputFileName);
    int counter = 0;
    for(int i = 0 ; i < store.numBooks ; i++)
    {
        if(store.books[i].cost - price < EPS)
            counter++;
    }
    out << counter << "\n";
    for(int i = 0 ; i < store.numBooks; i++)
    {
        if(store.books[i].cost - price < EPS)
        {
            counter--;
            out << store.books[i].name << "\n";
            if(counter)
                out << "\n";
        }
    }

    out.close();
}

int main()
{
    Bookstore store;
    initializeBookstore(store,"bookstore.txt");
    printBookstore(store);
    cout << hasBookWithISBN(store, "1234567890123") << endl;
    getAllBooksCheaperThan(store,20, "bookstore_out.txt");
	return 0;
}
