#pragma once
#include <iostream>

struct Book
{
	std::string title;
	double price;

	Book() {}
	Book(std::string t, double p)
	{
		this->title = t;
		this->price = p;
	}
};