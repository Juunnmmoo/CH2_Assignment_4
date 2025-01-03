#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std; // namespace std »ç¿ë

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};