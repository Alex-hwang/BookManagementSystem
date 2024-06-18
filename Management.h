#ifndef MANAGEMENT_H // ���û�ж���MANAGEMENT_H
#define MANAGEMENT_H // ����MANAGEMENT_H
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <cstdlib>
#include "Person.h"
#include "Book.h"

class Management
{
public:
	Management();
	~Management();

	// �û�����
	void addUser();
	void deleteUser();
	void showUserList() const;
	void searchUser() const;
	void modifyUserInfo();

	// �ÿ͹���
	void addVisitor();
	void deleteVisitor();
	void showVisitorList() const;
	void searchVisitor() const;
	void modifyVisitorInfo();

	// ����Ա����
	void addAdmin();
	void deleteAdmin();
	void showAdminList() const;
	void searchAdmin() const;
	void modifyAdminInfo();

	// ͼ�����
	void addBook();
	void deleteBook();
	void showBookList();
	void searchBookSpecifically();
	void borrowBook();
	void returnBook();
	void searchBook(std::vector<Book> m_bookList);
	void modifyBookInfo();

	// ������
	void showMostPopularBooks(); // ��ʾ���ܻ�ӭ���鼮��
	void showTopBorrowers();	 // ��ʾ�û���������
	void showChart();

	// ���ݹ���
	void saveData();
	void readData();

	// ���˵�
	void start();
	void showMainMenu() const;

	// �Ӳ˵�
	void userMenu();
	void visitorMenu();
	void adminMenu();
	void bookMenu();
	void dataMenu();

private:
	std::vector<User> m_userList;
	std::vector<Visitor> m_visitorList;
	std::vector<Admin> m_adminList;
	std::vector<Book> m_bookList;
};

#endif // MANAGEMENT_H // ����Ԥ����ָ��