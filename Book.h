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

// 书籍类
class Book : public LibraryItem
{
public:
	// 构造函数
	Book();
	Book(const Book& book);
	Book(std::string name, std::string author, std::string type, vector<std::string> keywords, std::string introduction, std::string ISBN, double price);
	Book(std::string name, std::string author, std::string type, vector<std::string> keywords, std::string introduction, bool borrowed, vector<std::string> borrowHistory, int borrowTimes, std::string ISBN, double price);

	~Book();

	// Getter和Setter
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

	// 显示书的信息
	void showBookInfo();

	// 借书
	void borrowBook(const User user);
	// 还书
	void returnBook();

	// 判断书是否被借出
	bool isBorrowed();

	// 模糊匹配
	// 判断书是否匹配关键字
	bool isMatchKeyword(std::string keyword);
	// 判断书是否匹配作者
	bool isMatchAuthor(std::string author);
	// 判断书是否匹配类别
	bool isMatchType(std::string type);
	// 判断书是否匹配书名
	bool isMatchName(std::string name);
	// 判断书是否模糊匹配简介
	bool isMatchIntroduction(std::string introduction);
	// 模糊判断
	bool isMatch(std::string word);

	// 运算符重载
	bool operator==(const Book& rhs) const;

	// 精准查询
	// 判断书是否匹配ISBN号
	bool isMatchISBN(std::string ISBN);

	// 修改书的信息
	void modifyBookInfo();

private:
	// 书的属性有：书名、作者、类别、关键字、简介、借阅状态、借阅历史、借阅次数、ISBN号、价格
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
