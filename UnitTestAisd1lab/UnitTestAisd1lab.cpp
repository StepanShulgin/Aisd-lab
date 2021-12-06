#include "pch.h"
#include "CppUnitTest.h"
#include "..\Aisd!lab\List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestAisd1lab
{
	TEST_CLASS(UnitTestAisd1lab)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			List newList;
			Assert::IsTrue(newList.get_size() == 0);
		}
		
		TEST_METHOD(Destructor)
		{
			List newList;
			newList.push_front(1);
			newList.push_front(1);
			newList.~List();
			Assert::IsTrue(newList.get_size() == 0);
		}
		TEST_METHOD(clear)
		{
			List newList;
			newList.clear();
			Assert::IsTrue(newList.isEmpty() == true);
			newList.push_back(0);
			newList.push_front(0);
			Assert::IsTrue(newList.isEmpty() == false);
			newList.clear();
			Assert::IsTrue(newList.isEmpty() == true);
		}
		TEST_METHOD(get_size)
		{
			List newList;
			Assert::IsTrue(newList.get_size() == 0);
			newList.push_back(0);
			Assert::IsTrue(newList.get_size() == 1);
			newList.push_front(0);
			Assert::IsTrue(newList.get_size() == 2);
		}
		TEST_METHOD(contains)
		{
			
			List newList1;
			newList1.push_back(1); 
			newList1.push_back(2);
			List newList2; 
			newList2.push_back(1);
			newList2.push_back(2);
			Assert::IsTrue(newList1.contains(newList2) == 1);
			newList1.clear();
			Assert::IsTrue(newList1.contains(newList2) == 0);
			newList1.push_back(1);
			newList1.push_back(2);
			newList1.push_back(3);
			newList1.push_back(4);
			newList1.push_back(5);
			newList2.clear();
			Assert::IsTrue(newList1.contains(newList2) == 1);
			newList2.pop_back();
			Assert::IsTrue(newList1.contains(newList2) == 1);
			
		}
		TEST_METHOD(remove)
		{
			List newList;
			newList.push_back(0);
			Assert::IsTrue(newList.get_size() == 1);
			
			try {
				newList.remove(3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			newList.remove(0);
			Assert::IsTrue(newList.get_size() == 0);
			
		}
		TEST_METHOD(push_front)
		{
			List newList;
			newList.push_front(0);
			Assert::IsTrue(newList.get_size() == 1);
			newList.push_front(0);
			Assert::IsTrue(newList.get_size() == 2);
		}
		TEST_METHOD(push_back)
		{
			List newList;
			newList.push_back(0);
			Assert::IsTrue(newList.get_size() == 1);
			newList.push_back(0);
			Assert::IsTrue(newList.get_size() == 2);
			
		}
		
		TEST_METHOD(pop_back)
		{
			List newList;
			newList.push_back(0);
			Assert::IsTrue(newList.get_size() == 1);
			newList.pop_back();
			Assert::IsTrue(newList.get_size() == 0);
			try {
				newList.pop_back();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Out of range", error.what());
			}
						
		}
		TEST_METHOD(pop_front)
		{
			List newList;
			newList.push_back(0);
			Assert::IsTrue(newList.get_size() == 1);
			newList.pop_front();
			Assert::IsTrue(newList.get_size() == 0);
			try {
				newList.pop_front();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Out of range", error.what());
			}
			
						
		}
		TEST_METHOD(isEmpty)
		{
			List newList;
			newList.push_back(0);
			newList.push_front(0);
			Assert::IsTrue(newList.isEmpty() == false);
			newList.clear();
			Assert::IsTrue(newList.isEmpty() == true);
		}
		TEST_METHOD(at)
		{
			List TestList;
			try {
				TestList.at(2);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			TestList.push_back(1);
			
			int element = TestList.at(0);
			Assert::IsTrue(element == 1);
		}
		TEST_METHOD(set)
		{
			List newList;
			newList.push_back(0);
			Assert::IsTrue(newList.get_size() == 1);
			try {
				newList.set(2, 0);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Out of range", error.what());
			}
			newList.set(0, 1);
			int x = newList.at(0);
			Assert::IsTrue(x == 0);
		}
		TEST_METHOD(insert)
		{
			List newList;

			newList.insert(1, 0);
			size_t size = newList.get_size();
			Assert::IsTrue(size == 1);
			newList.push_back(1);
			size = newList.get_size();
			newList.insert(1, 1);
			size = newList.get_size();
			Assert::IsTrue(size == 3);

		}
			
	};
}
