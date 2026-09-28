#include "Cart.h"

bool Cart::AddBook(Book* b)
{
	if (b != nullptr)
	{
		bks.push_back(b);
		return true;
	}
	return false;
}

int Cart::size()
{
	return bks.size();
}

int Cart::AddAll(std::list<Book*> bs)
{
	int count = 0;
	for (std::list<Book*>::iterator it = bs.begin(); 
			it != bs.end();it++)
	{
		if (AddBook(*it))
		{
			count++;
		}
	}
	return count;
}

bool Cart::removeBook(std::string title)
{
	std::list<Book*>::iterator it = bks.begin();
	while (it != bks.end())
	{
		if ((*it)->title == title)
		{
			it = bks.erase(it);
			return true;
		}
		it++;
	}
	return false;
	
}