#pragma once
#include "Book.h"
#include "BorrowManager.h"

class BookManager {
private:
    vector<Book> books; // 책 목록 저장
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
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back 사용
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;

        _BorrowManager.InitializeStock(books[_CurrentIndex++]);
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    void searchByTitle(const string& _title)
    {
        Book* book = _FindBookByTitle(_title);
        
        cout << "검색 결과" << endl;
       
        if (book == nullptr)
        {
            cout << "- 검색결과 없음 -" << endl;
            return;
        }

        cout << "- " << book->title << " by " << book->author << endl;
    }

    void searchByAuthor(const string& _author)
    {
        vector<Book*> books = _FindBookByAuthor(_author);

        cout << "검색 결과:" << endl;

        if (books.size() == 0)
        {
            cout << "- 검색결과 없음 -" << endl;
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
            cout << "- 제목 오류 -" << endl;
            return;
        }

        _BorrowManager.BorrowBook(_title);
    }

    void ReturnBook(const string& _title)
    {
        Book* book = _FindBookByTitle(_title);

        if (book == nullptr)
        {
            cout << "- 제목 오류 -" << endl;
            return;
        }

        _BorrowManager.ReturnBook(_title);
    }

    void DisplaySotck()
    {
        cout << "- 재고 목록 -" << endl;
        for (size_t i = 0; i < books.size(); i++)
        {
            _BorrowManager.DisplaySotck(books[i].title);
        }
    }

    void DisplaySotck(const string& _title)
    {
        cout << "- 재고 목록 -" << endl;
       
        Book* book = _FindBookByTitle(_title);

        if (book == nullptr)
        {
            cout << "- 제목 오류 -" << endl;
            return;
        }

        _BorrowManager.DisplaySotck(_title);
    }
};