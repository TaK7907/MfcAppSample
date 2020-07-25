#pragma once

#include <string>
#include <stdexcept>

class SerialNumberBarcodeData final
{
private:
	std::wstring _barcodeData;

	SerialNumberBarcodeData(const SerialNumberBarcodeData& other) = delete;


public:
	explicit SerialNumberBarcodeData(const std::wstring& data);
	virtual ~SerialNumberBarcodeData();

	static bool ValidateFormat(const std::wstring& data);

	const std::wstring GetModelCode();
	const std::wstring GetSerialNumber();
	const wchar_t* GetSerialNumberPtr();
	const std::wstring Get();
};

