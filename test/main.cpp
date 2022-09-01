#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title, author;
public:
    void setTitle(string title) {
        Book::title = title;
    }

    void setAuthor(string author) {
        Book::author = author;
    }

    string getTitle() { return title; }
    string getAuthor() { return author; }

    Book(string title, string author) {
        Book::title = title;
        Book::author = author;
    }
    Book() {}
};

class SingleBook : public Book {
private:
    double price;
public:
    void setPrice(double price) {
        SingleBook::price = price;
    }
    double getPrice() { return price; }
    void printBook() {
        cout << "Book title: " << getTitle() << endl;
        cout << "Book author: " << getAuthor() << endl;
        cout << "Book price: " << price << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    }
    SingleBook(string title, string author, double price) : Book(title, author) {
        SingleBook::price = price;
    }
    SingleBook(){}
};

class SeriesBook : public Book {
private:
    double alonePrice, fullSeriesPrice;
    int partNumber;
public:
    void setAlonePrice(double alonePrice) {
        SeriesBook::alonePrice = alonePrice;
    }
    void setFullSeriesPrice(double fullSeriesPrice) {
        SeriesBook::fullSeriesPrice = fullSeriesPrice;
    }
    void setPartNumber(int partNumber) {
        SeriesBook::partNumber = partNumber;
    }
    double getAlonePrice() { return alonePrice; }
    double getfullSeriesPrice() { return fullSeriesPrice; }
    int getPartNumber() { return partNumber; }

    void printBook() {
        cout << "Book title: " << getTitle() << endl;
        cout << "Book author: " << getAuthor() << endl;
        cout << "Book alone price: " << alonePrice << endl;
        cout << "Book full series price price: " << fullSeriesPrice << endl;
        cout << "Book part number: " << partNumber << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
    }
    SeriesBook(string title, string author, double alonePrice,
                double fullSeriesPrice, int partNumber) : Book(title, author) {
            SeriesBook::alonePrice = alonePrice;
            SeriesBook::fullSeriesPrice = fullSeriesPrice;
            SeriesBook::partNumber = partNumber;

    }
    SeriesBook() {}
};

class Library {
private:
    int singleBooksCount, seriesBooksCount;
    SingleBook singleBooks[100];
    SeriesBook seriesBooks[100];
public:
    void printAllBooks() {
        cout << "Starting to print all books...\n";
        for(int i = 0 ; i < singleBooksCount ; i++) {
            singleBooks[i].printBook();
        }
        for(int i = 0 ; i < seriesBooksCount ; i++) {
            seriesBooks[i].printBook();
        }
        cout << "Finished printing all books...\n";
    }

    void addBook() {
        int option;
        cout << "To add a single book please press 1\n";
        cout << "To add series of books please press 2\n";
        cin >> option;
        if(option == 1) {
            string title, author;
            double price;
            cout << "Please enter the title of the book: ";
            cin >> title;
            cout << "Please enter the author name of the book: ";
            cin >> author;
            cout << "Please enter the price of the book: ";
            cin >> price;
            SingleBook book(title, author, price);
            singleBooks[singleBooksCount] = book;
            singleBooksCount++;
        } else if(option == 2) {
            int partsCount;
            cout << "Please enter the parts count\n";
            cin >> partsCount;
            for(int i = 1 ; i <= partsCount ; i++) {
                cout << "Entering part number " << i << " data\n";
                string title, author;
                double alonePrice, fullSeriesPrice;
                cout << "Please enter the title of the book: ";
                cin >> title;
                cout << "Please enter the author name of the book: ";
                cin >> author;
                cout << "Please enter the single price of the book: ";
                cin >> alonePrice;
                cout << "Please enter the price of the book when bought as a full series: ";
                cin >> fullSeriesPrice;
                SeriesBook book(title, author, alonePrice, fullSeriesPrice, i);
                seriesBooks[seriesBooksCount] = book;
                seriesBooksCount++;
                cout << "finished entering part number " << i << " data\n";
            }
        } else {
            cout << "You entered wrong option.\n";
        }
    }

    void editBook() {
        cout << "Please enter the title of the book you need to edit\n";
        string title;
        cin >> title;
        bool edited = false;
        for(int i = 0 ; i < singleBooksCount ; i++) {
            if(singleBooks[i].getTitle() == title) {
                edited = true;
                cout << "Press 1 to edit title\n";
                cout << "Press 2 to edit author\n";
                cout << "Press 3 to edit price\n";
                int option;
                cin >> option;
                if(option == 1) {
                    cout << "please enter the new title: ";
                    cin >> title;
                    singleBooks[i].setTitle(title);
                } else if(option == 2) {
                    string author;
                    cout << "Please enter the new author name: ";
                    cin >> author;
                    singleBooks[i].setAuthor(author);
                } else {
                    double price;
                    cout << "Please enter the new price: ";
                    cin >> price;
                    singleBooks[i].setPrice(price);
                }
                break;
            }
        }

        if(edited == false) {
            for(int i = 0 ; i < seriesBooksCount ; i++) {
                if(seriesBooks[i].getTitle() == title) {
                    cout << "Press 1 to edit title\n";
                    cout << "Press 2 to edit author\n";
                    cout << "Press 3 to edit alone price\n";
                    cout << "Press 4 to edit full series price\n";
                    int option;
                    cin >> option;
                    if(option == 1) {
                        cout << "please enter the new title: ";
                        cin >> title;
                        seriesBooks[i].setTitle(title);
                    } else if(option == 2) {
                        string author;
                        cout << "Please enter the new author name: ";
                        cin >> author;
                        seriesBooks[i].setAuthor(author);
                    } else if(option ==3) {
                        double alonePrice;
                        cout << "Please enter the new alone price: ";
                        cin >> alonePrice;
                        seriesBooks[i].setAlonePrice(alonePrice);
                    }else if(option ==4) {
                        double fullSeriesPrice;
                        cout << "Please enter the new full series price: ";
                        cin >> fullSeriesPrice;
                        seriesBooks[i].setFullSeriesPrice(fullSeriesPrice);
                    }
                    break;
                }
            }
        }
    }
    Library() {
        singleBooksCount = seriesBooksCount = 0;
    }
};

int main()
{
    Library library;
    while(true) {
        cout << "Please press 1 to add a book\n";
        cout << "Please press 2 to edit a book\n";
        cout << "Please press 3 to print all books\n";
        cout << "print anything else to close the program\n";
        int option;
        cin >> option;
        if(option == 1) {
            library.addBook();
        } else if(option == 2) {
            library.editBook();
        } else if(option == 3) {
            library.printAllBooks();
        } else {
            break;
        }
    }
    return 0;
}
