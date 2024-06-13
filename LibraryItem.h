#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <string>

class LibraryItem {
public:
	virtual ~LibraryItem() = default;

	virtual std::string getTitle() = 0;
	virtual void setTitle(std::string title) = 0;
	virtual void showBookInfo() = 0;
};

#endif // LIBRARYITEM_H
