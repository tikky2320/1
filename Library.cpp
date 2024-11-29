//
// Created by Tomáš Výberčí on 28/11/2024.
//

#include "Library.h"



void Library::display() const {
    cout << "--------------------------\n"
         << "Name: " << name << endl
         << "Author: " << author << endl
         << "Genre: " << genre << endl
         << "Year: " << year << endl
         << "Price: " << price << endl
         << "--------------------------\n";
}
void addBook(vector<shared_ptr<Library>>& book, string name, string author, string genre, int year, double price) {
    book.push_back(make_shared<Library>(name, author, genre, year, price));
}
//
shared_ptr<Library> findBook(const vector<shared_ptr<Library>>& book, string const &name) {
    for (const auto& Book : book ) {
        if (Book->name == name) {
            return Book;
        }
    }
    return nullptr;
}


shared_ptr<Library> findBookA(vector<shared_ptr<Library>>& book, string author) {
    for (const auto& Book : book ) {
        if (Book->author == author) {
            return Book;
        }
    }
    return nullptr;
}
/*
shared_ptr<Library> findBookG(vector<shared_ptr<Library>>& book, string genre) {
            for (const auto& Book : book ) {
                if (Book->genre == genre) {
                    return Book;
                }
            }
            return nullptr;
}
shared_ptr<Library> findBookP(vector<shared_ptr<Library>>& book, double price) {
    for (const auto& Book : book ) {
        if (Book->price <= price) {
            return Book;
        }
    }
    return nullptr;
}

*/


void deleteBook(vector<shared_ptr<Library>>& book, string name) {
    for (auto it = book.begin(); it != book.end(); it++) {
        if ((*it)->name == name) {
            book.erase(it);
            cout << "Kniha s nazvom " << name << " bola vymazana.\n";
            return;
        }
    }
    cout << "Kniha s nazvom " << name << " nemohla byt ostranena. Nenasla sa v zozname.\n";
}

