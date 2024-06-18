#ifndef MANAGEMENT_H // 如果没有定义MANAGEMENT_H
#define MANAGEMENT_H // 定义MANAGEMENT_H
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

	// 用户管理
	void addUser();
	void deleteUser();
	void showUserList() const;
	void searchUser() const;
	void modifyUserInfo();

	// 访客管理
	void addVisitor();
	void deleteVisitor();
	void showVisitorList() const;
	void searchVisitor() const;
	void modifyVisitorInfo();

	// 管理员管理
	void addAdmin();
	void deleteAdmin();
	void showAdminList() const;
	void searchAdmin() const;
	void modifyAdminInfo();

	// 图书管理
	void addBook();
	void deleteBook();
	void showBookList();
	void searchBookSpecifically();
	void borrowBook();
	void returnBook();
	void searchBook(std::vector<Book> m_bookList);
	void modifyBookInfo();

	// 报表功能
	void showMostPopularBooks(); // 显示最受欢迎的书籍榜单
	void showTopBorrowers();	 // 显示用户借阅量榜单
	void showChart();

	// 数据管理
	void saveData();
	void readData();

	// 主菜单
	void start();
	void showMainMenu() const;

	// 子菜单
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

#endif // MANAGEMENT_H // 结束预处理指令