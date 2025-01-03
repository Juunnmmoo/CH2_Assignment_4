#pragma once
#include "Book.h"
#include "BorrowManager.h"

class BookManager {
private:
    vector<Book> books; // å ��� ����
    BorrowManager _BorrowManager;
    int _CurrentIndex = 0;

    Book* _FindBookByTitle(const string& _title)
    {
        for (size_t i = 0;i < books.size(); i++)
        {
            if (books[i].title == _title)
            {
                return &books[i];
            }
        }
        return nullptr;
    }

    vector<Book*> _FindBookByAuthor(const string & _author)
    {
        vector<Book*> arr_book;
        for (size_t i = 0;i < books.size(); i++)
        {
            if (books[i].author == _author)
            {
                arr_book.push_back(&books[i]);
            }
        }
        return arr_book;
    }

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;

        _BorrowManager.InitializeStock(books[_CurrentIndex++]);
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    void searchByTitle(const string& _title)
    {
        Book* book = _FindBookByTitle(_title);
        
        cout << "�˻� ���" << endl;
       
        if (book == nullptr)
        {
            cout << "- �˻���� ���� -" << endl;
            return;
        }

        cout << "- " << book->title << " by " << book->author << endl;
    }

    void searchByAuthor(const string& _author)
    {
        vector<Book*> books = _FindBookByAuthor(_author);

        cout << "�˻� ���:" << endl;

        if (books.size() == 0)
        {
            cout << "- �˻���� ���� -" << endl;
            return;
        }
        
        for (size_t i = 0; i < books.size(); i++)
        {
            cout << "- " << books[i]->title << " by " << books[i]->author << endl;

        }
    }


    void BorrowBook(const string& _title)
    {
        Book* book = _FindBookByTitle(_title);
        
        if (book == nullptr)
        {
            cout << "- ���� ���� -" << endl;
            return;
        }

        _BorrowManager.BorrowBook(_title);
    }

    void ReturnBook(const string& _title)
    {
        Book* book = _FindBookByTitle(_title);

        if (book == nullptr)
        {
            cout << "- ���� ���� -" << endl;
            return;
        }

        _BorrowManager.ReturnBook(_title);
    }

    void DisplaySotck()
    {
        cout << "- ��� ��� -" << endl;
        for (size_t i = 0; i < books.size(); i++)
        {
            _BorrowManager.DisplaySotck(books[i].title);
        }
    }

    void DisplaySotck(const string& _title)
    {
        cout << "- ��� ��� -" << endl;
       
        Book* book = _FindBookByTitle(_title);

        if (book == nullptr)
        {
            cout << "- ���� ���� -" << endl;
            return;
        }

        _BorrowManager.DisplaySotck(_title);
    }
};