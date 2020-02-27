#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CJob_1\UFrac.h"
#include "..\CJob_1\UFrac.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:


		TEST_METHOD(Test01)
		{
			TFrac mc;
			string result = "0/1";
			Assert::AreEqual(result, mc.GetFrac());
		}

		TEST_METHOD(Test02)
		{
			TFrac mc("1/2");
			string result = "1/2";
			Assert::AreEqual(result, mc.GetFrac());
		}

		TEST_METHOD(Test03)
		{
			TFrac mc(2,0);
			string result = "0/1";
			Assert::AreEqual(result, mc.GetFrac());
		}

		TEST_METHOD(Test04)
		{
			TFrac mc(1, -5);
			string result = "-1/5";
			Assert::AreEqual(result, mc.GetFrac());
		}

		TEST_METHOD(Test05)
		{
			TFrac mc(-1, 5);
			string result = "-1/5";
			Assert::AreEqual(result, mc.GetFrac());
		}

		TEST_METHOD(Test06)
		{
			TFrac mc(0, 5);
			string result = "0/1";
			Assert::AreEqual(result, mc.GetFrac());
		}


		TEST_METHOD(Test07)
		{
			TFrac mc(6, 2);
			string result = "3/1";
			Assert::AreEqual(result, mc.GetFrac());
		}

		TEST_METHOD(Test08)
		{
			TFrac mc(8, 28);
			string result = "2/7";
			Assert::AreEqual(result, mc.GetFrac());
		}

		TEST_METHOD(Test09)
		{
			TFrac mc(1, 2);
			string result = "1/2";
			Assert::AreEqual(result, mc.GetFrac());
		}

		TEST_METHOD(Test10)
		{
			TFrac f(1, 2);
			TFrac mc(f);
			string result = "1/2";
			Assert::AreEqual(result, mc.GetFrac());
		}

		TEST_METHOD(Test11)
		{
			TFrac a(1, 2);
			TFrac b(1, 2);
			TFrac c;
			c = a + b;
			string result = "1/1";
			Assert::AreEqual(result, c.GetFrac());
		}

		TEST_METHOD(Test12)
		{
			TFrac a(1, 2);
			TFrac b(1, 2);
			TFrac c;
			c = a * b;
			string result = "1/4";
			Assert::AreEqual(result, c.GetFrac());
		}

		TEST_METHOD(Test13)
		{
			TFrac a(1, 2);
			TFrac b(1, 2);
			TFrac c;
			c = a - b;
			string result = "0/1";
			Assert::AreEqual(result, c.GetFrac());
		}

		TEST_METHOD(Test14)
		{
			TFrac a(1, 2);
			TFrac b(0, 1);
			TFrac c;
			c = a / b;
			string result = "1/2";
			Assert::AreEqual(result, c.GetFrac());
		}

		TEST_METHOD(Test15)
		{
			TFrac a(1, 2);
			TFrac b(1, 2);
			TFrac c;
			c = a / b;
			string result = "1/1";
			Assert::AreEqual(result, c.GetFrac());
		}

		TEST_METHOD(Test16)
		{
			TFrac f(2, 5);
			TFrac mc;
			mc = f.Square();
			string result = "4/25";
			Assert::AreEqual(result, mc.GetFrac());
		}

		TEST_METHOD(Test17)
		{
			TFrac f(2, 5);
			TFrac mc;
			mc = f.Invert();
			string result = "5/2";
			Assert::AreEqual(result, mc.GetFrac());
		}

		TEST_METHOD(Test18)
		{
			TFrac f(2, 5);
			TFrac mc;
			mc = -f;
			string result = "-2/5";
			Assert::AreEqual(result, mc.GetFrac());
		}

		TEST_METHOD(Test19)
		{
			TFrac a(1, 2);
			TFrac b(1, 2);
			Assert::AreEqual(true, a == b);
		}

		TEST_METHOD(Test20)
		{
			TFrac a(2, 5);
			TFrac b(1, 2);
			Assert::AreEqual(false, a == b);
		}

		TEST_METHOD(Test21)
		{
			TFrac a(3, 4);
			TFrac b(1, 2);
			Assert::AreEqual(true, a > b);
		}

		TEST_METHOD(Test22)
		{
			TFrac a(1, 2);
			TFrac b(3, 4);
			Assert::AreEqual(false, a > b);
		}

		TEST_METHOD(Test23)
		{
			TFrac a(1, 2);
			TFrac b(3, 4);
			Assert::AreEqual(true, a < b);
		}

		TEST_METHOD(Test24)
		{
			TFrac a(3, 4);
			TFrac b(1, 2);
			Assert::AreEqual(false, a < b);
		}

		TEST_METHOD(Test25)
		{
			TFrac mc(1,2);
			string result = "1/2";
			Assert::AreEqual(result, mc.GetFrac());
		}

		TEST_METHOD(Test26)
		{
			TFrac mc(1,2);
			int result = 1;
			Assert::AreEqual(result, mc.GetNum<int>());
		}

		TEST_METHOD(Test27)
		{
			TFrac mc(1, 2);
			int result = 2;
			Assert::AreEqual(result, mc.GetDenom<int>());
		}

		TEST_METHOD(Test28)
		{
			TFrac mc(1, 2);
			string result = "1";
			Assert::AreEqual(result, mc.GetNum<string>());
		}

		TEST_METHOD(Test29)
		{
			TFrac mc(1, 2);
			string result = "2";
			Assert::AreEqual(result, mc.GetDenom<string>());
		}


	};
}