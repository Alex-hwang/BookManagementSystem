#ifndef BOOK_H
#define BOOK_H
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include "LibraryItem.h"
#include "Person.h"
using namespace std;

// �鼮��
class Book : public LibraryItem
{
public:
	// ���캯��
	Book();
	Book(const Book& book);
	Book(std::string name, std::string author, std::string type, vector<std::string> keywords, std::string introduction, std::string ISBN, double price);
	Book(std::string name, std::string author, std::string type, vector<std::string> keywords, std::string introduction, bool borrowed, vector<std::string> borrowHistory, int borrowTimes, std::string ISBN, double price);

	~Book();

	// Getter��Setter
	std::string getTitle();
	std::string getAuthor();
	std::string getType();
	vector<std::string> getKeywords();
	std::string getIntroduction();
	bool getBorrowed();
	vector<std::string> getBorrowHistory();
	int getBorrowTimes();
	std::string getISBN();
	double getPrice();

	void setTitle(std::string name);
	void setAuthor(std::string author);
	void setType(std::string type);
	void setKeywords(vector<std::string> keywords);
	void setIntroduction(std::string introduction);
	void setBorrowed(bool borrowed);
	void setBorrowHistory(vector<std::string> borrowHistory);
	void setBorrowTimes(int borrowTimes);
	void setISBN(std::string ISBN);
	void setPrice(double price);

	// ��ʾ�����Ϣ
	void showBookInfo();

	// ����
	void borrowBook(const User user);
	// ����
	void returnBook();

	// �ж����Ƿ񱻽��
	bool isBorrowed();

	// ģ��ƥ��
	// �ж����Ƿ�ƥ��ؼ���
	bool isMatchKeyword(std::string keyword);
	// �ж����Ƿ�ƥ������
	bool isMatchAuthor(std::string author);
	// �ж����Ƿ�ƥ�����
	bool isMatchType(std::string type);
	// �ж����Ƿ�ƥ������
	bool isMatchName(std::string name);
	// �ж����Ƿ�ģ��ƥ����
	bool isMatchIntroduction(std::string introduction);
	// ģ���ж�
	bool isMatch(std::string word);

	// ���������
	bool operator==(const Book& rhs) const;

	// ��׼��ѯ
	// �ж����Ƿ�ƥ��ISBN��
	bool isMatchISBN(std::string ISBN);

	// �޸������Ϣ
	void modifyBookInfo();

private:
	// ��������У����������ߡ���𡢹ؼ��֡���顢����״̬��������ʷ�����Ĵ�����ISBN�š��۸�
	std::string m_name;
	std::string m_author;
	std::string m_type;
	vector<std::string> m_keywords;
	std::string m_introduction;
	bool m_borrowed;
	vector<std::string> m_borrowHistory;
	int m_borrowTimes;
	std::string m_ISBN;
	double m_price;
};

#endif
