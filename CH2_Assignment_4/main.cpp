#include <iostream>
#include <vector>
#include <string>
#include "BookManager.h"

using namespace std; // namespace std ���

int main() {
    BookManager manager;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. �������� ���� �˻�" << endl; // �������� ���� �˻�
        cout << "4. �۰��̸����� ���� �˻�" << endl; // �۰��̸����� ���� �˻�
        cout << "5. å �뿩" << endl; // �۰��̸����� ���� �˻�
        cout << "6. å �ݳ�" << endl; // �۰��̸����� ���� �˻�
        cout << "7. ��� Ȯ��" << endl; // �۰��̸����� ���� �˻�
        cout << "8. å �������� ��� Ȯ��" << endl; // ���α׷� ����
        cout << "9. ����" << endl; // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        } else if (choice == 3) {
            // 3�� ����: ��� å ���
            string title;
            cout << "å ����: ";
            cin.ignore(); 
            getline(cin, title); 
            manager.searchByTitle(title);

        } else if (choice == 4) {
            // 4�� ����: ��� å ���

            string author;
            cout << "�۰� �̸� : " ;
            cin.ignore();
            getline(cin, author);
            manager.searchByAuthor(author);
        } else if (choice == 5) {
            // 5�� ����: å �뿩

            string title;
            cout << "å ���� : " ;
            cin.ignore();
            getline(cin, title);
            manager.BorrowBook(title);
        } else if (choice == 6) {
            // 6�� ����: å �ݳ�

            string title;
            cout << "å ���� : " ;
            cin.ignore();
            getline(cin, title);
            manager.ReturnBook(title);
        } else if (choice == 7) {
            // 4�� ����: ��� å ��� Ȯ��
            manager.DisplaySotck();
        }
        else if (choice == 8) {
            // 8�� ����: å �������� ��� Ȯ��
            string title;
            cout << "å ���� : ";
            cin.ignore();
            getline(cin, title);
            manager.DisplaySotck(title);
        }else if (choice == 9) {
            // 3�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
