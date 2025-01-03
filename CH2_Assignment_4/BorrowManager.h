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
			cout << "- " << _title << "�� ��� �����ϴ�!" << endl;
		}
		else
		{
			cout << "- " << _title << " - �뿩 ����!" << endl;
			stock[_title]--;
		}
	}

	void ReturnBook(const string& _title)
	{
		if (stock[_title] == 3)
		{
			cout << "- " << _title << " å�� ������ ���� �����ϴ�" << endl;
			return;
		}

		cout << "- " << _title << " - �ݳ� ����!" << endl;
		stock[_title]++;
	}

	void DisplaySotck(const string& _title)
	{
		cout << "- " << _title << " - �� ���� : " << stock[_title] << "��" << endl;
	}


};