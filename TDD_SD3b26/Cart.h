#pragma once
#include <list>
#include "Book.h"
class Cart
{
	std::list<Book*> bks;
public:
	bool AddBook(Book* b);
	int size();
	int AddAll(std::list<Book*> bs);
	bool removeBook(std::string title);
};

