#pragma once

#include <string>
#include <stdexcept>

class SerialNumberBarcodeData final
{
private:
	std::wstring _barcodeData;

public:
	explicit SerialNumberBarcodeData(const std::wstring& barcode);
	virtual ~SerialNumberBarcodeData();

	static bool ValidateValue(const std::wstring& value);

	const std::wstring GetModelCode() const;
	const std::wstring GetSerialNumber() const;
	const std::wstring Get() const;
};

