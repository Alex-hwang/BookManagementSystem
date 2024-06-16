#include "Management.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>

Management::Management()
{
	std::cout << "欢迎使用图书管理系统！" << std::endl;
	std::cout << endl;

	// 版权信息和软件基本信息
	std::cout << "版本：1.0.0" << std::endl;
	std::cout << "版权所有 Copyright 2024 图书管理系统团队" << std::endl;
	std::cout << "本软件用于管理图书馆的书籍和用户信息。" << std::endl;
	// std::cout << "官方网站：https://www.tsinghua.edu.cn" << std::endl;
	std::cout << "支持邮箱：hy-huang23@mails.tsinghua.edu.cn" << std::endl;
	std::cout << std::endl;

	system("pause");
	system("cls");
}

Management::~Management()
{
	system("cls");
	std::cout << "感谢使用图书管理系统！" << std::endl;
}

void Management::addUser()
{
	std::string name, phone;
	std::cout << "添加用户" << std::endl;
	std::cout << "请输入姓名：";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "请输入电话号码：";
	while (true)
	{
		std::getline(std::cin, phone);
		if (phone.length() != 11)
		{
			std::cout << "请输入11位电话号码：";
		}
		else
		{
			break;
		}
	}
	User user(name, phone);
	m_userList.push_back(user);
	std::cout << "用户 " << name << " 添加成功！" << std::endl;
	system("pause");
	system("cls");
}

void Management::deleteUser()
{
	std::string name;
	std::cout << "请输入要删除的用户名：";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (auto it = m_userList.begin(); it != m_userList.end(); ++it)
	{
		if (it->getName() == name)
		{
			std::cout << "是否删除用户 " << name << "？(y/n)";
			char choice;
			std::cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				m_userList.erase(it);
				std::cout << "删除成功！" << std::endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				std::cout << "取消删除！" << std::endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
	std::cout << "未找到该用户！" << std::endl;
	system("pause");
	system("cls");
}

void Management::showUserList() const
{
	system("cls");
	for (const auto& user : m_userList) {
		user.showUserInfo();
	}
	system("pause");
	system("cls");
}

void Management::searchUser() const
{
	std::string name;
	std::cout << "请输入要查找的用户名：";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (const auto& user : m_userList) {
		if (user.getName() == name) {
			user.showUserInfo();
			return;
		}
	}
	std::cout << "未找到该用户！" << std::endl;
}

void Management::modifyUserInfo()
{
	std::string name;
	std::cout << "请输入要修改的用户名：";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (auto& user : m_userList) {
		if (user.getName() == name) {
			user.modifyPersonInfo();
			return;
		}
	}
	std::cout << "未找到该用户！" << std::endl;
}

void Management::addVisitor()
{
	std::string name, phone;
	std::cout << "添加访客" << std::endl;
	std::cout << "请输入姓名：";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "请输入电话号码：";
	while (true)
	{
		std::getline(std::cin, phone);
		if (phone.length() != 11)
		{
			std::cout << "请输入11位电话号码：";
		}
		else
		{
			break;
		}
	}
	Visitor visitor(name, phone);
	m_visitorList.push_back(visitor);
	std::cout << "访客 " << name << " 添加成功！" << std::endl;
}

void Management::deleteVisitor()
{
	std::string name;
	std::cout << "请输入要删除的访客名：";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (auto it = m_visitorList.begin(); it != m_visitorList.end(); ++it)
	{
		if (it->getName() == name)
		{
			std::cout << "是否删除访客 " << name << "？(y/n)";
			char choice;
			std::cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				m_visitorList.erase(it);
				std::cout << "删除成功！" << std::endl;
				return;
			}
			else
			{
				std::cout << "取消删除！" << std::endl;
				return;
			}
		}
	}
	std::cout << "未找到该访客！" << std::endl;
}

void Management::showVisitorList() const {
	for (const auto& visitor : m_visitorList) {
		visitor.showVisitorInfo();
	}
}

void Management::searchVisitor() const
{
	std::string name;
	std::cout << "请输入要查找的访客名：";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (const auto& visitor : m_visitorList) {
		if (visitor.getName() == name) {
			visitor.showVisitorInfo();
			return;
		}
	}
	std::cout << "未找到该访客！" << std::endl;
}

void Management::modifyVisitorInfo()
{
	std::string name;
	std::cout << "请输入要修改的访客名：";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (auto& visitor : m_visitorList) {
		if (visitor.getName() == name) {
			visitor.modifyPersonInfo();
			return;
		}
	}
	std::cout << "未找到该访客！" << std::endl;
}

void Management::addAdmin()
{
	std::string name, phone;
	int borrowingNum, visitNum, authority;
	std::vector<std::string> borrowedHistory;
	std::string book;

	std::cout << "添加管理员" << std::endl;
	std::cout << "请输入姓名：";
	std::cin.ignore(); // 清除缓冲区
	std::getline(std::cin, name);
	std::cout << "请输入电话号码：";
	while (true)
	{
		std::getline(std::cin, phone);
		if (phone.length() != 11)
		{
			std::cout << "请输入11位电话号码：";
		}
		else
		{
			break;
		}
	}
	std::cout << "请输入借阅数量：";
	std::cin >> borrowingNum;
	std::cin.ignore(); // 清除缓冲区
	std::cout << "请输入借阅历史（以逗号分隔，输入完成后按回车）：";
	std::string borrowedHistoryInput;
	std::getline(std::cin, borrowedHistoryInput);
	std::istringstream iss(borrowedHistoryInput);
	while (std::getline(iss, book, ','))
	{
		borrowedHistory.push_back(book);
	}
	std::cout << "请输入访问次数：";
	std::cin >> visitNum;
	std::cout << "请输入权限等级：";
	std::cin >> authority;

	Admin admin(name, phone, borrowingNum, borrowedHistory, visitNum, authority);
	m_adminList.push_back(admin);
	std::cout << "管理员 " << name << " 添加成功！" << std::endl;
}

void Management::deleteAdmin()
{
	std::string name;
	std::cout << "请输入要删除的管理员名：";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (auto it = m_adminList.begin(); it != m_adminList.end(); ++it)
	{
		if (it->getName() == name)
		{
			std::cout << "是否删除管理员 " << name << "？(y/n)";
			char choice;
			std::cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				m_adminList.erase(it);
				std::cout << "删除成功！" << std::endl;
				return;
			}
			else
			{
				std::cout << "取消删除！" << std::endl;
				return;
			}
		}
	}
	std::cout << "未找到该管理员！" << std::endl;
}

void Management::showAdminList() const {
	for (const auto& admin : m_adminList) {
		admin.showAdminInfo();
	}
}

void Management::searchAdmin() const
{
	std::string name;
	std::cout << "请输入要查找的管理员名：";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (const auto& admin : m_adminList) {
		if (admin.getName() == name) {
			admin.showAdminInfo();
			return;
		}
	}
	std::cout << "未找到该管理员！" << std::endl;
}

void Management::modifyAdminInfo()
{
	std::string name;
	std::cout << "请输入要修改的管理员名：";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (auto& admin : m_adminList) {
		if (admin.getName() == name) {
			admin.modifyPersonInfo();
			return;
		}
	}
	std::cout << "未找到该管理员！" << std::endl;
}

void Management::addBook()
{
	std::string title, author, type, introduction, ISBN, keyword, history;
	double price;
	bool borrowed;
	int borrowTimes;
	std::vector<std::string> keywords, borrowHistory = { "图书馆购入" };

	std::cout << "添加书籍" << std::endl;
	std::cout << "请输入书名：";
	std::cin.ignore(); // 清除缓冲区
	std::getline(std::cin, title);
	std::cout << "请输入作者：";
	std::getline(std::cin, author);
	std::cout << "请输入类型：";
	std::getline(std::cin, type);
	std::cout << "请输入简介：";
	std::getline(std::cin, introduction);
	std::cout << "请输入ISBN：";
	while (true)
	{
		std::getline(std::cin, ISBN);
		if (ISBN.length() != 13)
		{
			std::cout << "ISBN号长度不正确，请重新输入：";
		}
		else
		{
			break;
		}
	}
	std::cout << "请输入价格：";
	std::cin >> price;

	std::cout << "请输入借阅状态（1 表示已借出，0 表示未借出）：";
	std::cin >> borrowed;
	std::cout << "请输入借阅次数：";
	std::cin >> borrowTimes;

	std::cin.ignore(); // 清除缓冲区
	std::cout << "请输入关键字（以逗号分隔）：";
	std::string keywordInput;
	std::getline(std::cin, keywordInput);
	std::istringstream keywordStream(keywordInput);
	while (std::getline(keywordStream, keyword, ','))
	{
		keywords.push_back(keyword);
	}

	std::cout << "请输入借阅历史（以逗号分隔，输入完成后按回车）：";
	std::string historyInput;
	std::getline(std::cin, historyInput);
	std::istringstream historyStream(historyInput);
	while (std::getline(historyStream, history, ','))
	{
		borrowHistory.push_back(history);
	}

	Book book(title, author, type, keywords, introduction, ISBN, price);
	book.setBorrowed(borrowed);
	book.setBorrowTimes(borrowTimes);
	book.setBorrowHistory(borrowHistory);
	m_bookList.push_back(book);
	std::cout << "书籍 " << title << " 添加成功！" << std::endl;
	system("pause");
	system("cls");
}

void Management::deleteBook()
{
	std::string ISBN;
	std::cout << "请输入要删除的书籍的ISBN：";
	std::cin.ignore();
	std::getline(std::cin, ISBN);
	for (auto it = m_bookList.begin(); it != m_bookList.end(); ++it)
	{
		if (it->getISBN() == ISBN)
		{
			std::cout << "是否删除书籍 " << it->getTitle() << "？(y/n)";
			char choice;
			std::cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				m_bookList.erase(it);
				std::cout << "删除成功！" << std::endl;
				return;
			}
			else
			{
				std::cout << "取消删除！" << std::endl;
				return;
			}
		}
	}
	std::cout << "未找到该书籍！" << std::endl;
}

void Management::showBookList() {
	for (auto& book : m_bookList) {
		book.showBookInfo();
	}
}

void Management::searchBookSpecifically()
{
	std::string ISBN;
	std::cout << "请输入要查找的ISBN：";
	while (true)
	{
		std::getline(std::cin, ISBN);
		if (ISBN.length() != 13)
		{
			std::cout << "请输入13位ISBN：";
		}
		else
		{
			break;
		}
	}
	for (auto& book : m_bookList) {
		if (book.isMatchISBN(ISBN)) {
			book.showBookInfo();
			return;
		}
	}
	std::cout << "未找到该书籍！" << std::endl;
}

void Management::borrowBook()
{
	std::string title;
	std::cout << "请输入要借阅的书名：";
	std::cin.ignore();
	std::getline(std::cin, title);
	for (auto& book : m_bookList) {
		if (book.getTitle() == title) {
			if (!book.isBorrowed()) {
				std::string userName;
				std::cout << "请输入借阅者姓名：";
				std::getline(std::cin, userName);
				for (auto& user : m_userList) {
					if (user.getName() == userName) {
						user.borrowBook(title);
						book.setBorrowed(true);
						book.borrowBook(user);
						std::cout << "借阅成功！" << std::endl;
						return;
					}
				}
				std::cout << "未找到该用户！" << std::endl;
				return;
			}
			else
			{
				std::cout << "该书已被借出！" << std::endl;
				return;
			}
		}
	}
	std::cout << "未找到该书籍！" << std::endl;
}

void Management::returnBook()
{
	std::string title;
	std::cout << "请输入要归还的书名：";
	std::cin.ignore();
	std::getline(std::cin, title);
	for (auto& book : m_bookList) {
		if (book.getTitle() == title) {
			if (book.isBorrowed()) {
				std::string userName;
				std::cout << "请输入归还者姓名：";
				std::getline(std::cin, userName);
				for (auto& user : m_userList) {
					if (user.getName() == userName) {
						user.returnBook(title);
						book.setBorrowed(false);
						std::cout << "归还成功！" << std::endl;
						return;
					}
				}
				std::cout << "未找到该用户！" << std::endl;
				return;
			}
			else
			{
				std::cout << "该书未被借出！" << std::endl;
				return;
			}
		}
	}
	std::cout << "未找到该书籍！" << std::endl;
}

void Management::saveData()
{
	std::ofstream outFile("data.dat");
	if (!outFile.is_open())
	{
		std::cout << "文件打开失败！" << std::endl;
		return;
	}

	std::cout << "正在保存数据";
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 != 0)
		{
			std::cout << "……";
			_sleep(100);
		}
		else
		{
			std::cout << "…………";
			_sleep(300);
		}
	}

	for (const auto& user : m_userList) {
		outFile << "User," << user.getName() << "," << user.getPhone() << "," << user.getborrowingNum() << ",";
		const auto& history = user.getBorrowedHistory();
		for (auto it = history.begin(); it != history.end(); ++it) {
			outFile << *it;
			if (std::next(it) != history.end())
				outFile << ";";
		}
		outFile << std::endl;
	}

	for (const auto& visitor : m_visitorList) {
		outFile << "Visitor," << visitor.getName() << "," << visitor.getPhone() << "," << visitor.getVisitNum() << std::endl;
	}

	for (const auto& admin : m_adminList) {
		outFile << "Admin," << admin.getName() << "," << admin.getPhone() << "," << admin.getVisitNum() << "," << admin.getborrowingNum() << "," << admin.getAuthority() << ",";
		const auto& history = admin.getBorrowedHistory();
		for (auto it = history.begin(); it != history.end(); ++it) {
			outFile << *it;
			if (std::next(it) != history.end())
				outFile << ";";
		}
		outFile << std::endl;
	}

	for (auto& book : m_bookList) {
		outFile << "Book," << book.getTitle() << "," << book.getAuthor() << "," << book.getType() << ","
			<< book.getIntroduction() << "," << book.getISBN() << "," << book.getBorrowed() << ","
			<< book.getBorrowTimes() << "," << book.getPrice() << ",";
		const auto& keywords = book.getKeywords();
		for (auto it = keywords.begin(); it != keywords.end(); ++it) {
			outFile << *it;
			if (std::next(it) != keywords.end())
				outFile << ";";
		}
		outFile << ",";
		const auto& borrowHistory = book.getBorrowHistory();
		for (auto it = borrowHistory.begin(); it != borrowHistory.end(); ++it) {
			outFile << *it;
			if (std::next(it) != borrowHistory.end())
				outFile << ";";
		}
		outFile << std::endl;
	}

	outFile.close();
	std::cout << "数据保存成功！" << std::endl;

	system("pause");
	system("cls");
}

// void Management::readData() {
//	std::ifstream inFile("data.dat");
//	if (!inFile.is_open()) {
//		std::cerr << "文件打开失败！" << std::endl;
//		return;
//	}
//
//	std::string line;
//	while (std::getline(inFile, line)) {
//		std::istringstream iss(line);
//		std::string type;
//		std::getline(iss, type, ',');
//
//		if (type == "User") {
//			std::string name, phone, temp;
//			int borrowingNum;
//			std::getline(iss, name, ',');
//			std::getline(iss, phone, ',');
//			iss >> borrowingNum;
//			iss.ignore(); // 跳过逗号
//			std::getline(iss, temp);
//			std::vector<std::string> borrowedHistory;
//			std::istringstream historyStream(temp);
//			std::string book;
//			while (std::getline(historyStream, book, ';')) {
//				if (!book.empty()) borrowedHistory.push_back(book);
//			}
//			User user(name, phone);
//			user.setborrowingNum(borrowingNum);
//			user.setBorrowedHistory(borrowedHistory);
//			m_userList.push_back(user);
//		}
//		else if (type == "Visitor") {
//			std::string name, phone;
//			int visitNum;
//			std::getline(iss, name, ',');
//			std::getline(iss, phone, ',');
//			iss >> visitNum;
//			Visitor visitor(name, phone, visitNum);
//			m_visitorList.push_back(visitor);
//		}
//		else if (type == "Admin") {
//			std::string name, phone, temp;
//			int visitNum, borrowingNum, authority;
//			std::getline(iss, name, ',');
//			std::getline(iss, phone, ',');
//			iss >> visitNum;
//			iss.ignore(); // 跳过逗号
//			iss >> borrowingNum;
//			iss.ignore(); // 跳过逗号
//			iss >> authority;
//			iss.ignore(); // 跳过逗号
//			std::getline(iss, temp);
//			std::vector<std::string> borrowedHistory;
//			std::istringstream historyStream(temp);
//			std::string book;
//			while (std::getline(historyStream, book, ';')) {
//				if (!book.empty()) borrowedHistory.push_back(book);
//			}
//			Admin admin(name, phone, borrowingNum, borrowedHistory, visitNum, authority);
//			m_adminList.push_back(admin);
//		}
//		else if (type == "Book") {
//			std::string title, author, bookType, introduction, ISBN, temp;
//			bool isBorrowed;
//			double price;
//			int borrowTimes;
//			std::getline(iss, title, ',');
//			std::getline(iss, author, ',');
//			std::getline(iss, bookType, ',');
//			std::getline(iss, introduction, ',');
//			std::getline(iss, ISBN, ',');
//			iss >> isBorrowed;
//			iss.ignore(); // 跳过逗号
//			iss >> borrowTimes;
//			iss.ignore(); // 跳过逗号
//			iss >> price;
//			iss.ignore(); // 跳过逗号
//			std::getline(iss, temp);
//			std::istringstream keywordStream(temp);
//			std::string keyword;
//			std::vector<std::string> keywords;
//			while (std::getline(keywordStream, keyword, ';')) {
//				if (!keyword.empty()) keywords.push_back(keyword);
//			}
//			std::getline(iss, temp);
//			std::istringstream historyStream(temp);
//			std::vector<std::string> borrowHistory;
//			std::string history;
//			while (std::getline(historyStream, history, ';')) {
//				if (!history.empty()) borrowHistory.push_back(history);
//			}
//			Book book(title, author, bookType, keywords, introduction, ISBN, price);
//			book.setBorrowed(isBorrowed);
//			book.setBorrowTimes(borrowTimes);
//			book.setBorrowHistory(borrowHistory);
//			m_bookList.push_back(book);
//		}
//	}
//
//	inFile.close();
// }

void Management::readData()
{
	std::ifstream inFile("data.dat");
	if (!inFile.is_open())
	{
		system("cls");
		std::cerr << "文件打开失败！" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	std::cout << "正在读取数据";
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 != 0)
		{
			std::cout << "……";
			_sleep(100);
		}
		else
		{
			std::cout << "…………";
			_sleep(300);
		}
	}
	std::string line;
	while (std::getline(inFile, line))
	{
		std::istringstream iss(line);
		std::string type;
		std::getline(iss, type, ',');

		if (type == "User")
		{
			std::string name, phone, temp;
			int borrowingNum;
			std::getline(iss, name, ',');
			std::getline(iss, phone, ',');
			iss >> borrowingNum;
			iss.ignore(); // 跳过逗号
			std::getline(iss, temp);
			std::vector<std::string> borrowedHistory;
			if (!temp.empty())
			{ // 检查借阅历史是否为空
				std::istringstream historyStream(temp);
				std::string book;
				while (std::getline(historyStream, book, ';'))
				{
					borrowedHistory.push_back(book);
				}
			}
			User user(name, phone);
			user.setborrowingNum(borrowingNum);
			user.setBorrowedHistory(borrowedHistory);
			m_userList.push_back(user);
		}
		else if (type == "Visitor")
		{
			std::string name, phone;
			int visitNum;
			std::getline(iss, name, ',');
			std::getline(iss, phone, ',');
			iss >> visitNum;
			Visitor visitor(name, phone, visitNum);
			m_visitorList.push_back(visitor);
		}
		else if (type == "Admin")
		{
			std::string name, phone, temp;
			int visitNum, borrowingNum, authority;
			std::getline(iss, name, ',');
			std::getline(iss, phone, ',');
			iss >> visitNum;
			iss.ignore(); // 跳过逗号
			iss >> borrowingNum;
			iss.ignore(); // 跳过逗号
			iss >> authority;
			iss.ignore(); // 跳过逗号
			std::getline(iss, temp);
			std::vector<std::string> borrowedHistory;
			if (!temp.empty())
			{ // 检查借阅历史是否为空
				std::istringstream historyStream(temp);
				std::string book;
				while (std::getline(historyStream, book, ';'))
				{
					borrowedHistory.push_back(book);
				}
			}
			Admin admin(name, phone, borrowingNum, borrowedHistory, visitNum, authority);
			m_adminList.push_back(admin);
		}
		// else if (type == "Book") {
		//	std::string title, author, bookType, introduction, ISBN, temp;
		//	bool isBorrowed;
		//	double price;
		//	int borrowTimes;
		//	std::getline(iss, title, ',');
		//	std::getline(iss, author, ',');
		//	std::getline(iss, bookType, ',');
		//	std::getline(iss, introduction, ',');
		//	std::getline(iss, ISBN, ',');
		//	iss >> isBorrowed;
		//	iss.ignore(); // 跳过逗号
		//	iss >> borrowTimes;
		//	iss.ignore(); // 跳过逗号
		//	iss >> price;
		//	iss.ignore(); // 跳过逗号
		//	std::getline(iss, temp);
		//	std::vector<std::string> keywords;
		//	if (!temp.empty()) { // 检查关键字是否为空
		//		std::istringstream keywordStream(temp);
		//		std::string keyword;
		//		while (std::getline(keywordStream, keyword, ';')) {
		//			keywords.push_back(keyword);
		//		}
		//	}
		//	std::getline(iss, temp);
		//	std::vector<std::string> borrowHistory;
		//	if (!temp.empty()) { // 检查借阅历史是否为空
		//		std::istringstream historyStream(temp);
		//		std::string history;
		//		while (std::getline(historyStream, history, ';')) {
		//			borrowHistory.push_back(history);
		//		}
		//	}
		//	Book book(title, author, bookType, keywords, introduction, ISBN, price);
		//	book.setBorrowed(isBorrowed);
		//	book.setBorrowTimes(borrowTimes);
		//	book.setBorrowHistory(borrowHistory);
		//	m_bookList.push_back(book);
		// }
		else if (type == "Book")
		{
			std::string title, author, bookType, introduction, ISBN, temp;
			bool isBorrowed;
			double price;
			int borrowTimes;
			std::getline(iss, title, ',');
			std::getline(iss, author, ',');
			std::getline(iss, bookType, ',');
			std::getline(iss, introduction, ',');
			std::getline(iss, ISBN, ',');
			iss >> isBorrowed;
			iss.ignore(); // 跳过逗号
			iss >> borrowTimes;
			iss.ignore(); // 跳过逗号
			iss >> price;
			iss.ignore();				  // 跳过逗号
			std::getline(iss, temp, ','); // 读取关键字，注意这里使用逗号作为分隔符
			std::vector<std::string> keywords;
			std::istringstream keywordStream(temp);
			std::string keyword;
			while (std::getline(keywordStream, keyword, ';'))
			{
				if (!keyword.empty())
					keywords.push_back(keyword);
			}
			// 读取借阅历史，这里假设借阅历史是单一条目
			std::getline(iss, temp); // 现在尝试读取借阅历史
			std::vector<std::string> borrowHistory;
			if (!temp.empty())
			{
				borrowHistory.push_back(temp);
			}
			Book book(title, author, bookType, keywords, introduction, ISBN, price);
			book.setBorrowed(isBorrowed);
			book.setBorrowTimes(borrowTimes);
			book.setBorrowHistory(borrowHistory);
			m_bookList.push_back(book);
		}
	}
	inFile.close();
	std::cout << "数据读取成功！" << std::endl;

	system("pause");
	system("cls");
}

// 移除字符串末尾的逗号
void removeTrailingComma(std::string& str) {
	if (!str.empty() && str.back() == ',') {
		str.pop_back();
	}
}

void Management::start()
{
	cout << "正在进入系统……";
	for (int i = 0; i < 10; i++)
	{
		if (i % 3 != 0)
		{
			cout << "……";
			_sleep(500);
		}
		else
		{
			cout << "…………";
			_sleep(800);
		}
	}
	system("cls");
	while (true)
	{
		showMainMenu();
		int choice;
		std::cout << "请输入您的选择：";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			dataMenu();
			break;
		case 2:
			userMenu();
			break;
		case 3:
			visitorMenu();
			break;
		case 4:
			adminMenu();
			break;
		case 5:
			bookMenu();
			break;
		case 0:
			return;
		default:
			std::cout << "输入错误！" << std::endl;
			break;
		}
	}
}

void Management::showMainMenu() const
{
	system("cls");

	std::cout << "………………………………………………………………" << std::endl;
	std::cout << "………………    主菜单   ………………" << std::endl;
	std::cout << "……………… 1. 数据管理 ………………" << std::endl;
	std::cout << "……………… 2. 用户管理 ………………" << std::endl;
	std::cout << "……………… 3. 访客管理 ………………" << std::endl;
	std::cout << "……………… 4. 管理员管理 ……………" << std::endl;
	std::cout << "……………… 5. 书籍管理 ………………" << std::endl;
	std::cout << "……………… 0. 退出系统 ………………" << std::endl;
	std::cout << "………………………………………………………………" << std::endl;
}

void Management::userMenu()
{
	system("cls");
	while (true)
	{
		std::cout << "……………… 用户管理菜单………………" << std::endl;
		std::cout << "……………… 1. 添加用户 ………………" << std::endl;
		std::cout << "……………… 2. 删除用户 ………………" << std::endl;
		std::cout << "……………… 3. 显示用户列表 …………" << std::endl;
		std::cout << "……………… 4. 查询用户 ………………" << std::endl;
		std::cout << "……………… 5. 修改用户信息 …………" << std::endl;
		std::cout << "……………… 6. 显示借阅排行榜 ………" << std::endl;
		std::cout << "……………… 7. 绘制借阅数量曲线 ……" << std::endl;
		std::cout << "……………… 0. 返回主菜单 ……………" << std::endl;
		int choice;
		std::cout << "请输入您的选择：";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			addUser();
			break;
		case 2:
			deleteUser();
			break;
		case 3:
			showUserList();
			break;
		case 4:
			searchUser();
			break;
		case 5:
			modifyUserInfo();
			break;
		case 6:
			showTopBorrowers();
			break;
		case 7:
			showChart();
			break;
		case 0:
			return;
		default:
			std::cout << "输入错误！" << std::endl;
			break;
		}
	}
}

void Management::visitorMenu()
{
	system("cls");
	while (true)
	{
		std::cout << "……………… 访客管理菜单………………" << std::endl;
		std::cout << "……………… 1. 添加访客 ………………" << std::endl;
		std::cout << "……………… 2. 删除访客 ………………" << std::endl;
		std::cout << "……………… 3. 显示访客列表 …………" << std::endl;
		std::cout << "……………… 4. 查询访客 ………………" << std::endl;
		std::cout << "……………… 5. 修改访客信息 …………" << std::endl;
		std::cout << "……………… 0. 返回主菜单 ……………" << std::endl;
		int choice;
		std::cout << "请输入您的选择：";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			addVisitor();
			break;
		case 2:
			deleteVisitor();
			break;
		case 3:
			showVisitorList();
			break;
		case 4:
			searchVisitor();
			break;
		case 5:
			modifyVisitorInfo();
			break;
		case 0:
			return;
		default:
			std::cout << "输入错误！" << std::endl;
			break;
		}
	}
}

void Management::adminMenu()
{
	system("cls");
	while (true)
	{
		std::cout << "……………… 管理员管理菜单………………" << std::endl;
		std::cout << "……………… 1. 添加管理员 ………………" << std::endl;
		std::cout << "……………… 2. 删除管理员 ………………" << std::endl;
		std::cout << "……………… 3. 显示管理员列表 …………" << std::endl;
		std::cout << "……………… 4. 查询管理员 ………………" << std::endl;
		std::cout << "……………… 5. 修改管理员信息 …………" << std::endl;
		std::cout << "……………… 0. 返回主菜单 ………………" << std::endl;
		int choice;
		std::cout << "请输入您的选择：";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			addAdmin();
			break;
		case 2:
			deleteAdmin();
			break;
		case 3:
			showAdminList();
			break;
		case 4:
			searchAdmin();
			break;
		case 5:
			modifyAdminInfo();
			break;
		case 0:
			return;
		default:
			std::cout << "输入错误！" << std::endl;
			break;
		}
	}
}

void Management::bookMenu()
{
	system("cls");
	while (true)
	{
		std::cout << "……………… 书籍管理菜单………………" << std::endl;
		std::cout << "……………… 1. 添加书籍 ………………" << std::endl;
		std::cout << "……………… 2. 删除书籍 ………………" << std::endl;
		std::cout << "……………… 3. 显示书籍列表 …………" << std::endl;
		std::cout << "……………… 4. 查找书籍（精确） ……" << std::endl;
		std::cout << "……………… 5. 借书 ……………………" << std::endl;
		std::cout << "……………… 6. 还书 ……………………" << std::endl;
		std::cout << "……………… 7. 查找书籍（模糊） ……" << std::endl;
		std::cout << "……………… 8. 修改书籍信息 …………" << std::endl;
		std::cout << "……………… 9. 显示受欢迎的书籍 ……" << std::endl;
		std::cout << "……………… 0. 返回主菜单 ……………" << std::endl;
		int choice;
		std::cout << "请输入您的选择：";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			addBook();
			break;
		case 2:
			deleteBook();
			break;
		case 3:
			showBookList();
			system("pause");
			break;
		case 4:
			searchBookSpecifically();
			break;
		case 5:
			borrowBook();
			break;
		case 6:
			returnBook();
			break;
		case 7:
			searchBook(m_bookList);
			break;
		case 8:
			modifyBookInfo();
			break;
		case 9:
			showMostPopularBooks();
			break;
		case 0:
			return;
		default:
			std::cout << "输入错误！" << std::endl;
			break;
		}
	}
}

void Management::dataMenu()
{
	system("cls");
	while (true)
	{
		std::cout << "……………… 数据管理菜单………………" << std::endl;
		std::cout << "……………… 1. 保存数据 ………………" << std::endl;
		std::cout << "……………… 2. 读取数据 ………………" << std::endl;
		std::cout << "……………… 0. 返回主菜单 ……………" << std::endl;
		int choice;
		std::cout << "请输入您的选择：";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			saveData();
			return;
		case 2:
			readData();
			return;
		case 0:
			return;
		default:
			std::cout << "输入错误！" << std::endl;
			break;
		}
	}
}

// 更全面的模糊查询书籍的方法
void Management::searchBook(std::vector<Book> m_bookList)
{
	std::string query;
	std::cout << "请输入查询字符串：";
	std::cin.ignore();
	std::getline(std::cin, query);

	std::vector<Book> result;
	std::string lowerQuery = query;
	// 将查询字符串转换为小写，以实现不区分大小写的搜索
	std::transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

	for (auto& book : m_bookList) {
		std::string title = book.getTitle();
		std::vector<string> keywords = book.getKeywords();
		std::string description = book.getIntroduction();

		// 将这些字段转换为小写
		// std::transform(title.begin(), title.end(), title.begin(), ::tolower);
		// for (auto& keyword : keywords) {
		// std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
		//}		std::transform(keywords.begin(), keywords.end(), keywords.begin(), ::tolower);
		// std::transform(description.begin(), description.end(), description.begin(), ::tolower);

		// 检查查询字符串是否为这些字段的子串
		if (title.find(lowerQuery) != std::string::npos ||
			std::find(keywords.begin(), keywords.end(), lowerQuery) != keywords.end() ||
			description.find(lowerQuery) != std::string::npos)
		{
			result.push_back(book);
		}
	}

	if (result.empty())
	{
		std::cout << "未找到相关书籍！" << std::endl;
	}
	else {
		for (auto& book : result) {
			book.showBookInfo();
		}
	}
}

void Management::showMostPopularBooks() {
	std::sort(m_bookList.begin(), m_bookList.end(), [](Book& a, Book& b) {
		return a.getBorrowTimes() > b.getBorrowTimes(); // 根据借阅次数降序排序
		});

	std::cout << "最受欢迎的书籍榜单：" << std::endl;
	for (auto& book : m_bookList) {
		std::cout << "书名：" << book.getTitle() << ", 借阅次数：" << book.getBorrowTimes() << std::endl;
	}
}

void Management::showTopBorrowers() {
	std::sort(m_userList.begin(), m_userList.end(), [](User& a, User& b) {
		return a.getborrowingNum() > b.getborrowingNum(); // 根据借阅数量降序排序
		});

	std::cout << "用户借阅量榜单：" << std::endl;
	for (auto& user : m_userList) {
		std::cout << "用户名：" << user.getName() << ", 借阅数量：" << user.getborrowingNum() << std::endl;
	}
}

void Management::modifyBookInfo()
{
	std::string title;
	std::cout << "请输入要修改的书名：";
	std::cin.ignore();
	std::getline(std::cin, title);
	for (auto& book : m_bookList) {
		if (book.getTitle() == title) {
			book.modifyBookInfo();
			return;
		}
	}
	std::cout << "未找到该书籍！" << std::endl;
}

void Management::showChart()
{
	system("cls");
	std::vector<std::pair<std::string, int>> user_num;
	// 填充user_num的代码保持不变
	for (const auto& user : m_userList)
	{
		user_num.push_back(std::make_pair(user.getName(), user.getborrowingNum()));
	}
	// 构建调用Python脚本的命令字符串
	std::string command = "python draw_chart.py"; // 根据你的系统环境，可能需要改为python3
	for (const auto& user : user_num)
	{
		// 将用户名和借阅数量作为命令行参数添加
		command += " \"" + user.first + "\" " + std::to_string(user.second);
	}
	//std::cout << command << std::endl;

	// 调用Python脚本
	int result = std::system(command.c_str());
	if (result != 0) {
		std::cerr << "调用Python脚本失败，返回值：" << result << std::endl;
	}
}