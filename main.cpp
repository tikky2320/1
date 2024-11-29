#include <iostream>
#include <string>
#include <vector>
#include "Library.h"
using namespace std;


int main() {
    string name;
    string author;
    string genre;
    int year = 0;
    double price = 0;
    int choice = 0;
    vector<shared_ptr<Library>> book;

    do {
        cout << "Vyber si zo zoznamu: \n"
             << "--------------------------\n"
             << "1 - pridat knihu\n"
             << "2 - vyhladat knihu\n"
             << "3 - zoznam knih\n"
             << "4 - odstranit knihu\n"
             << "0 - Ukoncit\n"
             << "--------------------------\n";
        cin >> choice;
        if (choice == static_cast<int>(menu::add)) {
                cout << "Pridanie knihy\n";
                cout << "Zadaj nazov knihy: ";
                cin.ignore();
                getline (cin,name);
                cout << "Zadaj autora knihy: ";
                getline (cin,author);
                cout << "Zadaj zaner knihy: ";
                getline (cin,genre);
                cout << "Zadaj rok knihy: ";
                cin >> year;
                cout << "Zadaj cenu knihy: ";
                cin >> price;
                addBook(book, name, author, genre, year, price);
                }

        else if (choice == static_cast<int>(menu::search)) { //static_cast<int> kvoli strongly typed enums
            cout << "Vyhladavanie knihy\n";
            string bookName;
            cout << "Zadaj nazov, autora, zaner alebo cenu knihy ktoru hladas";
            cin.ignore();
            getline (cin, bookName);
            //
             if (auto foundBookN = findBook(book, bookName)) {
                cout << "Knihu mame! " << endl
                << "Detaily knihy: \n";
                foundBookN->display();
            } else {
                cout << "Knihu s nazvom " << bookName << " bohuzial nemame. \n";
            }
           if (auto foundBookA = findBookA(book, bookName)) {
                cout << "Knihu mame! " << endl
                << "Detaily knihy: \n";
                foundBookA->display();
            } else {
                cout << "Knihu podla autora " << bookName << " bohuzial nemame. \n";
            }
            //
        } else if (choice != static_cast<int>(menu::list)) {
            if (choice == static_cast<int>(menu::del)) {
                string bookDelete;
                cout << "Ktoru knihu by si chcel vymazat?\n";
                cout << "Zoznam knih: \n";
                for (const auto &Book: book) {
                    Book->display();
                }
                cin.ignore();
                getline(cin, bookDelete);
                deleteBook(book, bookDelete);
            } else if (choice == static_cast<int>(menu::end)) {
                cout << "Dakujeme za pouzitie. ";
            } else {
                cout << "Neplatna volba. Pre ukoncenie stlac 0 \n";
            }
        } else {
            cout << "Zoznam knih\n";
            for (const auto &Book: book) {
                Book->display();
            }
        }
    } while (choice != 0);

    return 0;
}




//edit 25.11.24 - pridane strong typed enums