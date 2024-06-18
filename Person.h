#ifndef PERSON_H
#define PERSON_H

#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <cstdlib>

#include <string>

class Person {
protected:
	std::string m_name;
	std::string m_phone;

public:
	Person();
	Person(std::string name, std::string phone);
	virtual ~Person() = 0;

	std::string getName() const;
	std::string getPhone() const;

	void setName(std::string name);
	void setPhone(std::string phone);

	virtual void showPersonInfo() const;
	virtual void modifyPersonInfo();
};

class User : virtual public Person {
private:
	int m_borrowingNum;
	int m_borrowedNum;
	std::vector<std::string> m_borrowedHistory;

public:
	User();
	User(std::string name, std::string phone);
	User(std::string name, std::string phone, int borrowingNum, std::vector<std::string> borrowedHistory);

	~User() override;

	int getborrowingNum() const;
	int getBorrowedNum() const;
	std::vector<std::string> getBorrowedHistory() const;

	void setborrowingNum(int borrowingNum);
	void setBorrowedHistory(std::vector<std::string> borrowedHistory);

	void showUserInfo() const;
	void borrowBook(std::string bookName);
	void returnBook(std::string bookName);
	void showBorrowHistory() const;
};

class Visitor : virtual public Person {
private:
	int m_visitNum;

public:
	Visitor();
	Visitor(std::string name, std::string phone);
	Visitor(std::string name, std::string phone, int visitNum);

	~Visitor() override;

	int getVisitNum() const;
	void setVisitNum(int visitNum);

	void modifyVisitorInfo();
	void showVisitorInfo() const;
};

class Admin : public User, public Visitor {
private:
	int m_authority;

public:
	Admin();
	Admin(std::string name, std::string phone);
	Admin(std::string name, std::string phone, int borrowingNum, std::vector<std::string> borrowedHistory, int visitNum, int authority);

	~Admin() override;

	int getAuthority() const;
	void setAuthority(int authority);

	void modifyAdminInfo();
	void showAdminInfo() const;
};

#endif // PERSON_H
