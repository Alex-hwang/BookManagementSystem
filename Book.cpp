#include "Book.h"

// Book类的实现
Book::Book()
{
	m_name = "";
	m_author = "";
	m_type = "";
	m_keywords.clear();
	m_introduction = "";
	m_borrowed = false;
	m_borrowHistory = {};
	m_borrowTimes = 0;
	m_ISBN = "";
	m_price = 0;
}

Book::Book(std::string name, std::string author, std::string type, vector<std::string> keywords, std::string introduction, bool borrowed, vector<std::string> borrowHistory, int borrowTimes, std::string ISBN, double price)
{
	m_name = name;
	m_author = author;
	m_type = type;
	m_keywords = keywords;
	m_introduction = introduction;
	m_borrowed = borrowed;
	m_borrowHistory = borrowHistory;
	m_borrowTimes = borrowTimes;
	m_ISBN = ISBN;
	m_price = price;
}

Book::Book(const Book& book)
{
	m_name = book.m_name;
	m_author = book.m_author;
	m_type = book.m_type;
	m_keywords = book.m_keywords;
	m_introduction = book.m_introduction;
	m_borrowed = book.m_borrowed;
	m_borrowHistory = book.m_borrowHistory;
	m_borrowTimes = book.m_borrowTimes;
	m_ISBN = book.m_ISBN;
	m_price = book.m_price;
}

Book::Book(std::string title, std::string author, std::string type, std::vector<string> keywords, std::string introduction, std::string ISBN, double price)
{
	m_name = title;
	m_author = author;
	m_type = type;
	m_keywords = keywords;
	m_introduction = introduction;
	m_borrowed = false;
	m_borrowHistory = {};
	m_borrowTimes = 0;
	m_ISBN = ISBN;
	m_price = price;
}

Book::~Book()
{
	// cout << "Book对象被销毁" << endl;
}

std::string Book::getTitle()
{
	return m_name;
}

std::string Book::getAuthor()
{
	return m_author;
}

std::string Book::getType()
{
	return m_type;
}

vector<std::string> Book::getKeywords()
{
	return m_keywords;
}

std::string Book::getIntroduction()
{
	return m_introduction;
}

bool Book::getBorrowed()
{
	return m_borrowed;
}

vector<std::string> Book::getBorrowHistory()
{
	return m_borrowHistory;
}

int Book::getBorrowTimes()
{
	return m_borrowTimes;
}

std::string Book::getISBN()
{
	return m_ISBN;
}

double Book::getPrice()
{
	return m_price;
}

void Book::setTitle(std::string name)
{
	m_name = name;
}

void Book::setAuthor(std::string author)
{
	m_author = author;
}

void Book::setType(std::string type)
{
	m_type = type;
}

void Book::setKeywords(vector<std::string> keywords)
{
	m_keywords = keywords;
}

void Book::setIntroduction(std::string introduction)
{
	m_introduction = introduction;
}

void Book::setBorrowed(bool borrowed)
{
	m_borrowed = borrowed;
}

void Book::setBorrowHistory(vector<std::string> borrowHistory)
{
	m_borrowHistory = borrowHistory;
}

void Book::setBorrowTimes(int borrowTimes)
{
	m_borrowTimes = borrowTimes;
}

void Book::setISBN(std::string ISBN)
{
	m_ISBN = ISBN;
}

void Book::setPrice(double price)
{
	m_price = price;
}

void Book::showBookInfo()
{
	cout << "书名：" << m_name << endl;
	cout << "作者：" << m_author << endl;
	cout << "类型：" << m_type << endl;
	cout << "关键词：";
	for (int i = 0; i < m_keywords.size(); i++)
	{
		cout << m_keywords[i] << " ";
	}
	cout << endl;
	cout << "简介：" << m_introduction << endl;
	cout << "借阅状态：" << (m_borrowed ? "已借出" : "未借出") << endl;
	cout << "ISBN号：" << m_ISBN << endl;
	cout << "价格：" << m_price << endl;
	cout << "借阅历史：";
	for (int i = 0; i < m_borrowHistory.size(); i++)
	{
		cout << m_borrowHistory[i] << " ";
	}
	cout << endl;
}

void Book::borrowBook(User user)
{
	m_borrowed = true;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	std::string borrowTime = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday);
	m_borrowHistory.push_back(user.getName() + " " + borrowTime);
	m_borrowTimes++;
}

void Book::returnBook()
{
	m_borrowed = false;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	std::string returnTime = to_string(1900 + ltm->tm_year) + "-" + to_string(1 + ltm->tm_mon) + "-" + to_string(ltm->tm_mday);
	m_borrowHistory.back() += " " + returnTime;
	m_borrowTimes++;
}

bool Book::isBorrowed()
{
	return m_borrowed;
}

bool Book::isMatchKeyword(std::string keyword)
{
	for (const auto& kw : m_keywords)
	{
		if (kw.find(keyword) != std::string::npos)
		{
			return true;
		}
	}
	return false;
}

bool Book::isMatchAuthor(std::string author)
{
	return m_author.find(author) != std::string::npos;
}

bool Book::isMatchType(std::string type)
{
	return m_type.find(type) != std::string::npos;
}

bool Book::isMatchName(std::string name)
{
	return m_name.find(name) != std::string::npos;
}

bool Book::isMatchIntroduction(std::string introduction)
{
	return m_introduction.find(introduction) != std::string::npos;
}

bool Book::isMatchISBN(std::string ISBN)
{
	return m_ISBN == ISBN;
}

bool Book::isMatch(std::string word)
{
	return isMatchKeyword(word) || isMatchAuthor(word) || isMatchType(word) || isMatchName(word) || isMatchIntroduction(word);
}

void Book::modifyBookInfo()
{
	cout << "请输入书名：";
	cin >> m_name;
	cout << "请输入作者：";
	cin >> m_author;
	cout << "请输入类型：";
	cin >> m_type;
	cout << "请输入关键词：";
	while (true)
	{
		std::string keyword;
		cin >> keyword;
		m_keywords.push_back(keyword);
		cout << "是否继续输入关键词？(y/n)";
		char c;
		cin >> c;
		if (c == 'n')
		{
			break;
		}
	}
	cout << "请输入简介：";
	cin >> m_introduction;
	cout << "请输入ISBN号：";
	while (true)
	{
		cin >> m_ISBN;
		if (m_ISBN.size() != 13)
		{
			cout << "ISBN号长度不正确，请重新输入：";
		}
		else
		{
			break;
		}
	}
	cout << "请输入价格：";
	while (true)
	{
		cin >> m_price;
		if (m_price < 0)
		{
			cout << "价格不能为负，请重新输入：";
		}
		else
		{
			break;
		}
	}
}