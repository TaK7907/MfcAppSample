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

		TEST_METHOD(�������`��)
		{
			const std::wstring input{ L"123456--aB3" };
			SerialNumberBarcodeData sut{ input };

			Assert::AreEqual(input, sut.Get());
			Assert::AreEqual(L"123456", sut.GetSerialNumber().c_str());
			Assert::AreEqual(L"aB3", sut.GetModelCode().c_str());
		}

		TEST_METHOD(�n�C�t��1�s��)
		{
			const std::wstring input{ L"123456-Xy4" };
			SerialNumberBarcodeData sut{ input };

			Assert::AreEqual(L"", sut.Get().c_str());
			Assert::AreEqual(L"", sut.GetModelCode().c_str());
			Assert::AreEqual(L"", sut.GetSerialNumber().c_str());
		}

		TEST_METHOD(������)
		{
			const std::wstring input{ L"" };
			SerialNumberBarcodeData sut{ input };

			Assert::AreEqual(input, sut.Get());
			Assert::AreEqual(L"", sut.GetModelCode().c_str());
			Assert::AreEqual(L"", sut.GetSerialNumber().c_str());
		}
	};
}
