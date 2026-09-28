#include <list>
#include "pch.h"
#include "CppUnitTest.h"
#include "../TDD_SD3b26/Cart.h"
#include "../TDD_SD3b26/Book.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace TestShoppingCart
{
	TEST_CLASS(TestShoppingCart)
	{
		Book* b1, * b2, *b3;
	public:
		TEST_METHOD_INITIALIZE(setUp)
		{
			b1 = new Book("Harry Potter and the Philosophers Stone", 6.99);
			b2 = new Book("The Widow", 16.99);
			b3 = new Book("Lord of the Rings", 9.99);

		}
		TEST_METHOD_CLEANUP(TearDown)
		{
			delete b1, b2, b3;
		}
		TEST_METHOD(testAddBook)
		{
			Cart c;

			Assert::AreEqual(0, c.size(), L"Number of books is incorrect at start");
			Assert::IsTrue(c.AddBook(b1));
			Assert::AreEqual(1, c.size(), L"Number of books is incorrect");
		}
		TEST_METHOD(testAddNoBook)
		{
			Cart c;
			Assert::IsFalse(c.AddBook(nullptr));
			Assert::AreEqual(0, c.size(), L"Number of books is incorrect");

		}

		TEST_METHOD(testAddAllWithNullptr)
		{
			Cart c;
			Assert::AreEqual(0, c.size(), L"Number of books is incorrect at start");

			list<Book*> books;
			books.push_back(b1);
			books.push_back(b2);
			books.push_back(nullptr);

			int added = c.AddAll(books);
			Assert::AreEqual(2, added, L"Number of books returned by function");
			Assert::AreEqual(2, c.size(), L"Number of books is incorrect in cart");

		}
		TEST_METHOD(testAddAllWithAllValidBooks)
		{
			Cart c;
			Assert::AreEqual(0, c.size(), L"Number of books is incorrect at start");

			list<Book*> books;
			books.push_back(b1);
			books.push_back(b2);
			books.push_back(b3);

			int added = c.AddAll(books);
			Assert::AreEqual(3, added, L"Number of books returned by function");
			Assert::AreEqual(3, c.size(), L"Number of books is incorrect in cart");

		}
		TEST_METHOD(testAddAllWithEmptyList)
		{
			Cart c;
			Assert::AreEqual(0, c.size(), L"Number of books is incorrect at start");
			list<Book*> books;
			int added = c.AddAll(books);
			Assert::AreEqual(0, added, L"Number of books returned by function");
			Assert::AreEqual(0, c.size(), L"Number of books is incorrect in cart");

		}

		TEST_METHOD(testRemoveValid)
		{
			Cart c;
			c.AddBook(b1);
			c.AddBook(b2);
			Assert::AreEqual(2, c.size());
			Assert::IsTrue(c.removeBook("The Widow"));
			Assert::AreEqual(1, c.size());
		}
		TEST_METHOD(testRemoveInValid)
		{
			Cart c;
			c.AddBook(b1);
			c.AddBook(b2);
			Assert::AreEqual(2, c.size());
			Assert::IsFalse(c.removeBook(""));
			Assert::AreEqual(2, c.size());
		}

		TEST_METHOD(testGetSubtotalEmptyList)
		{
			Cart c;
			Assert::AreEqual(0, c.size());
			Assert::AreEqual(0.00, c.getSubTotal(), 0.01);
		}
		TEST_METHOD(testGetSubtotalOneBook)
		{
			Cart c;
			c.AddBook(b1);
			Assert::AreEqual(1, c.size());
			Assert::AreEqual(6.99, c.getSubTotal(), 0.01);
		}
		TEST_METHOD(testGetSubtotalTwoBook)
		{
			Cart c;
			c.AddBook(b1);
			c.AddBook(b2);
			Assert::AreEqual(2, c.size());
			Assert::AreEqual(23.98, c.getSubTotal(), 0.01);
		}
	};
}
