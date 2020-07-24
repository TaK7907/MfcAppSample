#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "ValueObjects/SerialNumberBarcodeData.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MfcAppTest
{
	TEST_CLASS(SerialNumberBarcodeDataTest)
	{
	public:

		TEST_METHOD(AsExpected)
		{
			auto sut = SerialNumberBarcodeData(L"123456--aB3");

			Assert::AreEqual(L"123456--aB3", sut.Get().c_str());
			Assert::AreEqual(L"123456", sut.GetSerialNumber().c_str());
			Assert::AreEqual(L"aB3", sut.GetModelCode().c_str());
		}

		TEST_METHOD(BadFormat)
		{
			auto sut = SerialNumberBarcodeData(L"123456-Xy4");

			Assert::AreEqual(L"", sut.Get().c_str());
			Assert::AreEqual(L"", sut.GetModelCode().c_str());
			Assert::AreEqual(L"", sut.GetSerialNumber().c_str());
		}

		TEST_METHOD(Empty)
		{
			auto sut = SerialNumberBarcodeData(L"");

			Assert::AreEqual(L"", sut.Get().c_str());
			Assert::AreEqual(L"", sut.GetModelCode().c_str());
			Assert::AreEqual(L"", sut.GetSerialNumber().c_str());
		}
	};
}
