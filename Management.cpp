#include "Management.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>

Management::Management()
{
	std::cout << "��ӭʹ��ͼ�����ϵͳ��" << std::endl;
	std::cout << endl;

	// ��Ȩ��Ϣ�����������Ϣ
	std::cout << "�汾��1.0.0" << std::endl;
	std::cout << "��Ȩ���� Copyright 2024 ͼ�����ϵͳ�Ŷ�" << std::endl;
	std::cout << "��������ڹ���ͼ��ݵ��鼮���û���Ϣ��" << std::endl;
	// std::cout << "�ٷ���վ��https://www.tsinghua.edu.cn" << std::endl;
	std::cout << "֧�����䣺hy-huang23@mails.tsinghua.edu.cn" << std::endl;
	std::cout << std::endl;

	system("pause");
	system("cls");
}

Management::~Management()
{
	system("cls");
	std::cout << "��лʹ��ͼ�����ϵͳ��" << std::endl;
}

void Management::addUser()
{
	std::string name, phone;
	std::cout << "����û�" << std::endl;
	std::cout << "������������";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "������绰���룺";
	while (true)
	{
		std::getline(std::cin, phone);
		if (phone.length() != 11)
		{
			std::cout << "������11λ�绰���룺";
		}
		else
		{
			break;
		}
	}
	User user(name, phone);
	m_userList.push_back(user);
	std::cout << "�û� " << name << " ��ӳɹ���" << std::endl;
	system("pause");
	system("cls");
}

void Management::deleteUser()
{
	std::string name;
	std::cout << "������Ҫɾ�����û�����";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (auto it = m_userList.begin(); it != m_userList.end(); ++it)
	{
		if (it->getName() == name)
		{
			std::cout << "�Ƿ�ɾ���û� " << name << "��(y/n)";
			char choice;
			std::cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				m_userList.erase(it);
				std::cout << "ɾ���ɹ���" << std::endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				std::cout << "ȡ��ɾ����" << std::endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}
	std::cout << "δ�ҵ����û���" << std::endl;
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
	std::cout << "������Ҫ���ҵ��û�����";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (const auto& user : m_userList) {
		if (user.getName() == name) {
			user.showUserInfo();
			return;
		}
	}
	std::cout << "δ�ҵ����û���" << std::endl;
}

void Management::modifyUserInfo()
{
	std::string name;
	std::cout << "������Ҫ�޸ĵ��û�����";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (auto& user : m_userList) {
		if (user.getName() == name) {
			user.modifyPersonInfo();
			return;
		}
	}
	std::cout << "δ�ҵ����û���" << std::endl;
}

void Management::addVisitor()
{
	std::string name, phone;
	std::cout << "��ӷÿ�" << std::endl;
	std::cout << "������������";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "������绰���룺";
	while (true)
	{
		std::getline(std::cin, phone);
		if (phone.length() != 11)
		{
			std::cout << "������11λ�绰���룺";
		}
		else
		{
			break;
		}
	}
	Visitor visitor(name, phone);
	m_visitorList.push_back(visitor);
	std::cout << "�ÿ� " << name << " ��ӳɹ���" << std::endl;
}

void Management::deleteVisitor()
{
	std::string name;
	std::cout << "������Ҫɾ���ķÿ�����";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (auto it = m_visitorList.begin(); it != m_visitorList.end(); ++it)
	{
		if (it->getName() == name)
		{
			std::cout << "�Ƿ�ɾ���ÿ� " << name << "��(y/n)";
			char choice;
			std::cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				m_visitorList.erase(it);
				std::cout << "ɾ���ɹ���" << std::endl;
				return;
			}
			else
			{
				std::cout << "ȡ��ɾ����" << std::endl;
				return;
			}
		}
	}
	std::cout << "δ�ҵ��÷ÿͣ�" << std::endl;
}

void Management::showVisitorList() const {
	for (const auto& visitor : m_visitorList) {
		visitor.showVisitorInfo();
	}
}

void Management::searchVisitor() const
{
	std::string name;
	std::cout << "������Ҫ���ҵķÿ�����";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (const auto& visitor : m_visitorList) {
		if (visitor.getName() == name) {
			visitor.showVisitorInfo();
			return;
		}
	}
	std::cout << "δ�ҵ��÷ÿͣ�" << std::endl;
}

void Management::modifyVisitorInfo()
{
	std::string name;
	std::cout << "������Ҫ�޸ĵķÿ�����";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (auto& visitor : m_visitorList) {
		if (visitor.getName() == name) {
			visitor.modifyPersonInfo();
			return;
		}
	}
	std::cout << "δ�ҵ��÷ÿͣ�" << std::endl;
}

void Management::addAdmin()
{
	std::string name, phone;
	int borrowingNum, visitNum, authority;
	std::vector<std::string> borrowedHistory;
	std::string book;

	std::cout << "��ӹ���Ա" << std::endl;
	std::cout << "������������";
	std::cin.ignore(); // ���������
	std::getline(std::cin, name);
	std::cout << "������绰���룺";
	while (true)
	{
		std::getline(std::cin, phone);
		if (phone.length() != 11)
		{
			std::cout << "������11λ�绰���룺";
		}
		else
		{
			break;
		}
	}
	std::cout << "���������������";
	std::cin >> borrowingNum;
	std::cin.ignore(); // ���������
	std::cout << "�����������ʷ���Զ��ŷָ���������ɺ󰴻س�����";
	std::string borrowedHistoryInput;
	std::getline(std::cin, borrowedHistoryInput);
	std::istringstream iss(borrowedHistoryInput);
	while (std::getline(iss, book, ','))
	{
		borrowedHistory.push_back(book);
	}
	std::cout << "��������ʴ�����";
	std::cin >> visitNum;
	std::cout << "������Ȩ�޵ȼ���";
	std::cin >> authority;

	Admin admin(name, phone, borrowingNum, borrowedHistory, visitNum, authority);
	m_adminList.push_back(admin);
	std::cout << "����Ա " << name << " ��ӳɹ���" << std::endl;
}

void Management::deleteAdmin()
{
	std::string name;
	std::cout << "������Ҫɾ���Ĺ���Ա����";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (auto it = m_adminList.begin(); it != m_adminList.end(); ++it)
	{
		if (it->getName() == name)
		{
			std::cout << "�Ƿ�ɾ������Ա " << name << "��(y/n)";
			char choice;
			std::cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				m_adminList.erase(it);
				std::cout << "ɾ���ɹ���" << std::endl;
				return;
			}
			else
			{
				std::cout << "ȡ��ɾ����" << std::endl;
				return;
			}
		}
	}
	std::cout << "δ�ҵ��ù���Ա��" << std::endl;
}

void Management::showAdminList() const {
	for (const auto& admin : m_adminList) {
		admin.showAdminInfo();
	}
}

void Management::searchAdmin() const
{
	std::string name;
	std::cout << "������Ҫ���ҵĹ���Ա����";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (const auto& admin : m_adminList) {
		if (admin.getName() == name) {
			admin.showAdminInfo();
			return;
		}
	}
	std::cout << "δ�ҵ��ù���Ա��" << std::endl;
}

void Management::modifyAdminInfo()
{
	std::string name;
	std::cout << "������Ҫ�޸ĵĹ���Ա����";
	std::cin.ignore();
	std::getline(std::cin, name);
	for (auto& admin : m_adminList) {
		if (admin.getName() == name) {
			admin.modifyPersonInfo();
			return;
		}
	}
	std::cout << "δ�ҵ��ù���Ա��" << std::endl;
}

void Management::addBook()
{
	std::string title, author, type, introduction, ISBN, keyword, history;
	double price;
	bool borrowed;
	int borrowTimes;
	std::vector<std::string> keywords, borrowHistory = { "ͼ��ݹ���" };

	std::cout << "����鼮" << std::endl;
	std::cout << "������������";
	std::cin.ignore(); // ���������
	std::getline(std::cin, title);
	std::cout << "���������ߣ�";
	std::getline(std::cin, author);
	std::cout << "���������ͣ�";
	std::getline(std::cin, type);
	std::cout << "�������飺";
	std::getline(std::cin, introduction);
	std::cout << "������ISBN��";
	while (true)
	{
		std::getline(std::cin, ISBN);
		if (ISBN.length() != 13)
		{
			std::cout << "ISBN�ų��Ȳ���ȷ�����������룺";
		}
		else
		{
			break;
		}
	}
	std::cout << "������۸�";
	std::cin >> price;

	std::cout << "���������״̬��1 ��ʾ�ѽ����0 ��ʾδ�������";
	std::cin >> borrowed;
	std::cout << "��������Ĵ�����";
	std::cin >> borrowTimes;

	std::cin.ignore(); // ���������
	std::cout << "������ؼ��֣��Զ��ŷָ�����";
	std::string keywordInput;
	std::getline(std::cin, keywordInput);
	std::istringstream keywordStream(keywordInput);
	while (std::getline(keywordStream, keyword, ','))
	{
		keywords.push_back(keyword);
	}

	std::cout << "�����������ʷ���Զ��ŷָ���������ɺ󰴻س�����";
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
	std::cout << "�鼮 " << title << " ��ӳɹ���" << std::endl;
	system("pause");
	system("cls");
}

void Management::deleteBook()
{
	std::string ISBN;
	std::cout << "������Ҫɾ�����鼮��ISBN��";
	std::cin.ignore();
	std::getline(std::cin, ISBN);
	for (auto it = m_bookList.begin(); it != m_bookList.end(); ++it)
	{
		if (it->getISBN() == ISBN)
		{
			std::cout << "�Ƿ�ɾ���鼮 " << it->getTitle() << "��(y/n)";
			char choice;
			std::cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				m_bookList.erase(it);
				std::cout << "ɾ���ɹ���" << std::endl;
				return;
			}
			else
			{
				std::cout << "ȡ��ɾ����" << std::endl;
				return;
			}
		}
	}
	std::cout << "δ�ҵ����鼮��" << std::endl;
}

void Management::showBookList() {
	for (auto& book : m_bookList) {
		book.showBookInfo();
	}
}

void Management::searchBookSpecifically()
{
	std::string ISBN;
	std::cout << "������Ҫ���ҵ�ISBN��";
	while (true)
	{
		std::getline(std::cin, ISBN);
		if (ISBN.length() != 13)
		{
			std::cout << "������13λISBN��";
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
	std::cout << "δ�ҵ����鼮��" << std::endl;
}

void Management::borrowBook()
{
	std::string title;
	std::cout << "������Ҫ���ĵ�������";
	std::cin.ignore();
	std::getline(std::cin, title);
	for (auto& book : m_bookList) {
		if (book.getTitle() == title) {
			if (!book.isBorrowed()) {
				std::string userName;
				std::cout << "�����������������";
				std::getline(std::cin, userName);
				for (auto& user : m_userList) {
					if (user.getName() == userName) {
						user.borrowBook(title);
						book.setBorrowed(true);
						book.borrowBook(user);
						std::cout << "���ĳɹ���" << std::endl;
						return;
					}
				}
				std::cout << "δ�ҵ����û���" << std::endl;
				return;
			}
			else
			{
				std::cout << "�����ѱ������" << std::endl;
				return;
			}
		}
	}
	std::cout << "δ�ҵ����鼮��" << std::endl;
}

void Management::returnBook()
{
	std::string title;
	std::cout << "������Ҫ�黹��������";
	std::cin.ignore();
	std::getline(std::cin, title);
	for (auto& book : m_bookList) {
		if (book.getTitle() == title) {
			if (book.isBorrowed()) {
				std::string userName;
				std::cout << "������黹��������";
				std::getline(std::cin, userName);
				for (auto& user : m_userList) {
					if (user.getName() == userName) {
						user.returnBook(title);
						book.setBorrowed(false);
						std::cout << "�黹�ɹ���" << std::endl;
						return;
					}
				}
				std::cout << "δ�ҵ����û���" << std::endl;
				return;
			}
			else
			{
				std::cout << "����δ�������" << std::endl;
				return;
			}
		}
	}
	std::cout << "δ�ҵ����鼮��" << std::endl;
}

void Management::saveData()
{
	std::ofstream outFile("data.dat");
	if (!outFile.is_open())
	{
		std::cout << "�ļ���ʧ�ܣ�" << std::endl;
		return;
	}

	std::cout << "���ڱ�������";
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 != 0)
		{
			std::cout << "����";
			_sleep(100);
		}
		else
		{
			std::cout << "��������";
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
	std::cout << "���ݱ���ɹ���" << std::endl;

	system("pause");
	system("cls");
}

// void Management::readData() {
//	std::ifstream inFile("data.dat");
//	if (!inFile.is_open()) {
//		std::cerr << "�ļ���ʧ�ܣ�" << std::endl;
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
//			iss.ignore(); // ��������
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
//			iss.ignore(); // ��������
//			iss >> borrowingNum;
//			iss.ignore(); // ��������
//			iss >> authority;
//			iss.ignore(); // ��������
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
//			iss.ignore(); // ��������
//			iss >> borrowTimes;
//			iss.ignore(); // ��������
//			iss >> price;
//			iss.ignore(); // ��������
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
		std::cerr << "�ļ���ʧ�ܣ�" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	std::cout << "���ڶ�ȡ����";
	for (int i = 0; i < 5; i++)
	{
		if (i % 2 != 0)
		{
			std::cout << "����";
			_sleep(100);
		}
		else
		{
			std::cout << "��������";
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
			iss.ignore(); // ��������
			std::getline(iss, temp);
			std::vector<std::string> borrowedHistory;
			if (!temp.empty())
			{ // ��������ʷ�Ƿ�Ϊ��
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
			iss.ignore(); // ��������
			iss >> borrowingNum;
			iss.ignore(); // ��������
			iss >> authority;
			iss.ignore(); // ��������
			std::getline(iss, temp);
			std::vector<std::string> borrowedHistory;
			if (!temp.empty())
			{ // ��������ʷ�Ƿ�Ϊ��
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
		//	iss.ignore(); // ��������
		//	iss >> borrowTimes;
		//	iss.ignore(); // ��������
		//	iss >> price;
		//	iss.ignore(); // ��������
		//	std::getline(iss, temp);
		//	std::vector<std::string> keywords;
		//	if (!temp.empty()) { // ���ؼ����Ƿ�Ϊ��
		//		std::istringstream keywordStream(temp);
		//		std::string keyword;
		//		while (std::getline(keywordStream, keyword, ';')) {
		//			keywords.push_back(keyword);
		//		}
		//	}
		//	std::getline(iss, temp);
		//	std::vector<std::string> borrowHistory;
		//	if (!temp.empty()) { // ��������ʷ�Ƿ�Ϊ��
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
			iss.ignore(); // ��������
			iss >> borrowTimes;
			iss.ignore(); // ��������
			iss >> price;
			iss.ignore();				  // ��������
			std::getline(iss, temp, ','); // ��ȡ�ؼ��֣�ע������ʹ�ö�����Ϊ�ָ���
			std::vector<std::string> keywords;
			std::istringstream keywordStream(temp);
			std::string keyword;
			while (std::getline(keywordStream, keyword, ';'))
			{
				if (!keyword.empty())
					keywords.push_back(keyword);
			}
			// ��ȡ������ʷ��������������ʷ�ǵ�һ��Ŀ
			std::getline(iss, temp); // ���ڳ��Զ�ȡ������ʷ
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
	std::cout << "���ݶ�ȡ�ɹ���" << std::endl;

	system("pause");
	system("cls");
}

// �Ƴ��ַ���ĩβ�Ķ���
void removeTrailingComma(std::string& str) {
	if (!str.empty() && str.back() == ',') {
		str.pop_back();
	}
}

void Management::start()
{
	cout << "���ڽ���ϵͳ����";
	for (int i = 0; i < 10; i++)
	{
		if (i % 3 != 0)
		{
			cout << "����";
			_sleep(500);
		}
		else
		{
			cout << "��������";
			_sleep(800);
		}
	}
	system("cls");
	while (true)
	{
		showMainMenu();
		int choice;
		std::cout << "����������ѡ��";
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
			std::cout << "�������" << std::endl;
			break;
		}
	}
}

void Management::showMainMenu() const
{
	system("cls");

	std::cout << "������������������������������������������������" << std::endl;
	std::cout << "������������    ���˵�   ������������" << std::endl;
	std::cout << "������������ 1. ���ݹ��� ������������" << std::endl;
	std::cout << "������������ 2. �û����� ������������" << std::endl;
	std::cout << "������������ 3. �ÿ͹��� ������������" << std::endl;
	std::cout << "������������ 4. ����Ա���� ����������" << std::endl;
	std::cout << "������������ 5. �鼮���� ������������" << std::endl;
	std::cout << "������������ 0. �˳�ϵͳ ������������" << std::endl;
	std::cout << "������������������������������������������������" << std::endl;
}

void Management::userMenu()
{
	system("cls");
	while (true)
	{
		std::cout << "������������ �û�����˵�������������" << std::endl;
		std::cout << "������������ 1. ����û� ������������" << std::endl;
		std::cout << "������������ 2. ɾ���û� ������������" << std::endl;
		std::cout << "������������ 3. ��ʾ�û��б� ��������" << std::endl;
		std::cout << "������������ 4. ��ѯ�û� ������������" << std::endl;
		std::cout << "������������ 5. �޸��û���Ϣ ��������" << std::endl;
		std::cout << "������������ 6. ��ʾ�������а� ������" << std::endl;
		std::cout << "������������ 7. ���ƽ����������� ����" << std::endl;
		std::cout << "������������ 0. �������˵� ����������" << std::endl;
		int choice;
		std::cout << "����������ѡ��";
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
			std::cout << "�������" << std::endl;
			break;
		}
	}
}

void Management::visitorMenu()
{
	system("cls");
	while (true)
	{
		std::cout << "������������ �ÿ͹���˵�������������" << std::endl;
		std::cout << "������������ 1. ��ӷÿ� ������������" << std::endl;
		std::cout << "������������ 2. ɾ���ÿ� ������������" << std::endl;
		std::cout << "������������ 3. ��ʾ�ÿ��б� ��������" << std::endl;
		std::cout << "������������ 4. ��ѯ�ÿ� ������������" << std::endl;
		std::cout << "������������ 5. �޸ķÿ���Ϣ ��������" << std::endl;
		std::cout << "������������ 0. �������˵� ����������" << std::endl;
		int choice;
		std::cout << "����������ѡ��";
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
			std::cout << "�������" << std::endl;
			break;
		}
	}
}

void Management::adminMenu()
{
	system("cls");
	while (true)
	{
		std::cout << "������������ ����Ա����˵�������������" << std::endl;
		std::cout << "������������ 1. ��ӹ���Ա ������������" << std::endl;
		std::cout << "������������ 2. ɾ������Ա ������������" << std::endl;
		std::cout << "������������ 3. ��ʾ����Ա�б� ��������" << std::endl;
		std::cout << "������������ 4. ��ѯ����Ա ������������" << std::endl;
		std::cout << "������������ 5. �޸Ĺ���Ա��Ϣ ��������" << std::endl;
		std::cout << "������������ 0. �������˵� ������������" << std::endl;
		int choice;
		std::cout << "����������ѡ��";
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
			std::cout << "�������" << std::endl;
			break;
		}
	}
}

void Management::bookMenu()
{
	system("cls");
	while (true)
	{
		std::cout << "������������ �鼮����˵�������������" << std::endl;
		std::cout << "������������ 1. ����鼮 ������������" << std::endl;
		std::cout << "������������ 2. ɾ���鼮 ������������" << std::endl;
		std::cout << "������������ 3. ��ʾ�鼮�б� ��������" << std::endl;
		std::cout << "������������ 4. �����鼮����ȷ�� ����" << std::endl;
		std::cout << "������������ 5. ���� ����������������" << std::endl;
		std::cout << "������������ 6. ���� ����������������" << std::endl;
		std::cout << "������������ 7. �����鼮��ģ���� ����" << std::endl;
		std::cout << "������������ 8. �޸��鼮��Ϣ ��������" << std::endl;
		std::cout << "������������ 9. ��ʾ�ܻ�ӭ���鼮 ����" << std::endl;
		std::cout << "������������ 0. �������˵� ����������" << std::endl;
		int choice;
		std::cout << "����������ѡ��";
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
			std::cout << "�������" << std::endl;
			break;
		}
	}
}

void Management::dataMenu()
{
	system("cls");
	while (true)
	{
		std::cout << "������������ ���ݹ���˵�������������" << std::endl;
		std::cout << "������������ 1. �������� ������������" << std::endl;
		std::cout << "������������ 2. ��ȡ���� ������������" << std::endl;
		std::cout << "������������ 0. �������˵� ����������" << std::endl;
		int choice;
		std::cout << "����������ѡ��";
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
			std::cout << "�������" << std::endl;
			break;
		}
	}
}

// ��ȫ���ģ����ѯ�鼮�ķ���
void Management::searchBook(std::vector<Book> m_bookList)
{
	std::string query;
	std::cout << "�������ѯ�ַ�����";
	std::cin.ignore();
	std::getline(std::cin, query);

	std::vector<Book> result;
	std::string lowerQuery = query;
	// ����ѯ�ַ���ת��ΪСд����ʵ�ֲ����ִ�Сд������
	std::transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

	for (auto& book : m_bookList) {
		std::string title = book.getTitle();
		std::vector<string> keywords = book.getKeywords();
		std::string description = book.getIntroduction();

		// ����Щ�ֶ�ת��ΪСд
		// std::transform(title.begin(), title.end(), title.begin(), ::tolower);
		// for (auto& keyword : keywords) {
		// std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
		//}		std::transform(keywords.begin(), keywords.end(), keywords.begin(), ::tolower);
		// std::transform(description.begin(), description.end(), description.begin(), ::tolower);

		// ����ѯ�ַ����Ƿ�Ϊ��Щ�ֶε��Ӵ�
		if (title.find(lowerQuery) != std::string::npos ||
			std::find(keywords.begin(), keywords.end(), lowerQuery) != keywords.end() ||
			description.find(lowerQuery) != std::string::npos)
		{
			result.push_back(book);
		}
	}

	if (result.empty())
	{
		std::cout << "δ�ҵ�����鼮��" << std::endl;
	}
	else {
		for (auto& book : result) {
			book.showBookInfo();
		}
	}
}

void Management::showMostPopularBooks() {
	std::sort(m_bookList.begin(), m_bookList.end(), [](Book& a, Book& b) {
		return a.getBorrowTimes() > b.getBorrowTimes(); // ���ݽ��Ĵ�����������
		});

	std::cout << "���ܻ�ӭ���鼮�񵥣�" << std::endl;
	for (auto& book : m_bookList) {
		std::cout << "������" << book.getTitle() << ", ���Ĵ�����" << book.getBorrowTimes() << std::endl;
	}
}

void Management::showTopBorrowers() {
	std::sort(m_userList.begin(), m_userList.end(), [](User& a, User& b) {
		return a.getborrowingNum() > b.getborrowingNum(); // ���ݽ���������������
		});

	std::cout << "�û��������񵥣�" << std::endl;
	for (auto& user : m_userList) {
		std::cout << "�û�����" << user.getName() << ", ����������" << user.getborrowingNum() << std::endl;
	}
}

void Management::modifyBookInfo()
{
	std::string title;
	std::cout << "������Ҫ�޸ĵ�������";
	std::cin.ignore();
	std::getline(std::cin, title);
	for (auto& book : m_bookList) {
		if (book.getTitle() == title) {
			book.modifyBookInfo();
			return;
		}
	}
	std::cout << "δ�ҵ����鼮��" << std::endl;
}

void Management::showChart()
{
	system("cls");
	std::vector<std::pair<std::string, int>> user_num;
	// ���user_num�Ĵ��뱣�ֲ���
	for (const auto& user : m_userList)
	{
		user_num.push_back(std::make_pair(user.getName(), user.getborrowingNum()));
	}
	// ��������Python�ű��������ַ���
	std::string command = "python draw_chart.py"; // �������ϵͳ������������Ҫ��Ϊpython3
	for (const auto& user : user_num)
	{
		// ���û����ͽ���������Ϊ�����в������
		command += " \"" + user.first + "\" " + std::to_string(user.second);
	}
	//std::cout << command << std::endl;

	// ����Python�ű�
	int result = std::system(command.c_str());
	if (result != 0) {
		std::cerr << "����Python�ű�ʧ�ܣ�����ֵ��" << result << std::endl;
	}
}