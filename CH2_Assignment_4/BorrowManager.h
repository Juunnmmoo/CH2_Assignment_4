#pragma once
#include <unordered_map>
#include "Book.h"


class BorrowManager
{
private:
	unordered_map<string,int> stock;

public:
	void InitializeStock(const Book& _book) 
	{
		stock.insert({ _book.title, 3 });
	}

	void BorrowBook(const string& _title)
	{
		if (stock[_title] == 0)
		{
			cout << "- " << _title << "의 재고가 없습니다!" << endl;
		}
		else
		{
			cout << "- " << _title << " - 대여 성공!" << endl;
			stock[_title]--;
		}
	}

	void ReturnBook(const string& _title)
	{
		if (stock[_title] == 3)
		{
			cout << "- " << _title << " 책을 빌리신 적이 없습니다" << endl;
			return;
		}

		cout << "- " << _title << " - 반납 성공!" << endl;
		stock[_title]++;
	}

	void DisplaySotck(const string& _title)
	{
		cout << "- " << _title << " - 의 재고는 : " << stock[_title] << "권" << endl;
	}


};