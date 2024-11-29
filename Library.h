//
// Created by Tomáš Výberčí on 28/11/2024.
//

#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>
using namespace std;



class Library{
public:
    string const author;
    string const genre;
    int year;
    double price;
    string name;
    Library (string& name, string& author, string& genre, const int year, const double price)
    : name(name),author(author), genre(genre), year(year), price(price) {}
    ~Library()= default;
    void display() const;
};
void addBook(vector<shared_ptr<Library>>& book, string name,
             string author, string genre, int year, double price);

shared_ptr<Library> findBook(vector<shared_ptr<Library>>& book, string name);

shared_ptr<Library> findBookA(vector<shared_ptr<Library>>& book, string author);
/*shared_ptr<Library> findBookG(vector<shared_ptr<Library>>& book, string genre);
shared_ptr<Library> findBookP(vector<shared_ptr<Library>>& book, double price);
*/
void deleteBook(vector<shared_ptr<Library>>& book, string name);

enum class menu { //strongly typed enums
    add = 1,
    search,
    list,
    del,
    end,
};

#endif //LIBRARY_H
