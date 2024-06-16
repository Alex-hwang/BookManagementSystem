#include "Person.h"
#include <iostream>

// Person 类的实现
Person::Person() : m_name("Unknown"), m_phone("Unknown") {}

Person::Person(std::string name, std::string phone) : m_name(name), m_phone(phone) {}

Person::~Person() {}

std::string Person::getName() const
{
	return m_name;
}

std::string Person::getPhone() const
{
	return m_phone;
}

void Person::setName(std::string name)
{
	m_name = name;
}

void Person::setPhone(std::string phone)
{
	m_phone = phone;
}

void Person::showPersonInfo() const
{
	std::cout << "Name: " << m_name << ", Phone: " << m_phone << std::endl;
}

void Person::modifyPersonInfo()
{
	std::cout << "Enter new name: ";
	std::cin >> m_name;
	std::cout << "Enter new phone: ";
	std::cin >> m_phone;
}

// User 类的实现
User::User() : Person(), m_borrowingNum(0) {}

User::User(std::string name, std::string phone) : Person(name, phone), m_borrowingNum(0) {}

User::User(std::string name, std::string phone, int borrowingNum, std::vector<std::string> borrowedHistory)
	: Person(name, phone), m_borrowingNum(borrowingNum), m_borrowedHistory(borrowedHistory) {}

User::~User() {}

int User::getborrowingNum() const
{
	return m_borrowingNum;
}

int User::getBorrowedNum() const
{
	return m_borrowedNum;
}

std::vector<std::string> User::getBorrowedHistory() const
{
	return m_borrowedHistory;
}

void User::setborrowingNum(int borrowingNum)
{
	m_borrowingNum = borrowingNum;
}

void User::setBorrowedHistory(std::vector<std::string> borrowedHistory)
{
	m_borrowedHistory = borrowedHistory;
}

void User::showUserInfo() const
{
	showPersonInfo();
	std::cout << "Borrowed Number: " << m_borrowingNum << std::endl;
	std::cout << "Borrowed History: ";
	for (const auto &book : m_borrowedHistory)
	{
		std::cout << book << " ";
	}
	std::cout << std::endl;
}

void User::borrowBook(std::string bookName)
{
	m_borrowingNum++;
	m_borrowedNum++;
	m_borrowedHistory.push_back(bookName);
}

void User::returnBook(std::string bookName)
{
	auto it = std::find(m_borrowedHistory.begin(), m_borrowedHistory.end(), bookName);
	if (it != m_borrowedHistory.end() && m_borrowingNum > 0)
	{
		// m_borrowingNum--;
		return;
	}
}

void User::showBorrowHistory() const
{
	std::cout << "Borrowed History: ";
	for (const auto &book : m_borrowedHistory)
	{
		std::cout << book << " ";
	}
	std::cout << std::endl;
}

// Visitor 类的实现
Visitor::Visitor() : Person(), m_visitNum(0) {}

Visitor::Visitor(std::string name, std::string phone) : Person(name, phone), m_visitNum(0) {}

Visitor::Visitor(std::string name, std::string phone, int visitNum) : Person(name, phone), m_visitNum(visitNum) {}

Visitor::~Visitor() {}

int Visitor::getVisitNum() const
{
	return m_visitNum;
}

void Visitor::setVisitNum(int visitNum)
{
	m_visitNum = visitNum;
}

void Visitor::modifyVisitorInfo()
{
	modifyPersonInfo();
	std::cout << "Enter new visit number: ";
	std::cin >> m_visitNum;
}

void Visitor::showVisitorInfo() const
{
	showPersonInfo();
	std::cout << "Visit Number: " << m_visitNum << std::endl;
}

// Admin 类的实现
Admin::Admin() : Person(), User(), Visitor(), m_authority(0) {}

Admin::Admin(std::string name, std::string phone)
	: Person(name, phone), User(name, phone), Visitor(name, phone), m_authority(0) {}

Admin::Admin(std::string name, std::string phone, int borrowingNum, std::vector<std::string> borrowedHistory, int visitNum, int authority)
	: Person(name, phone), User(name, phone, borrowingNum, borrowedHistory), Visitor(name, phone, visitNum), m_authority(authority) {}

Admin::~Admin() {}

int Admin::getAuthority() const
{
	return m_authority;
}

void Admin::setAuthority(int authority)
{
	m_authority = authority;
}

void Admin::modifyAdminInfo()
{
	modifyPersonInfo();
	std::cout << "Enter new authority level: ";
	std::cin >> m_authority;
}

void Admin::showAdminInfo() const
{
	showUserInfo();
	showVisitorInfo();
	std::cout << "Authority Level: " << m_authority << std::endl;
}