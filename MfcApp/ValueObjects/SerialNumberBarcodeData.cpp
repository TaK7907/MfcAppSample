#include "../pch.h"
#include "SerialNumberBarcodeData.h"
#include <regex>


const std::wregex BarcodeFormat(LR"((\d{6})--(\w{3}))");

enum class MatchingPart : int {
	WholeBarcode,
	SerialNumber,
	ModelCode,
	MaxMatchCount,
};


SerialNumberBarcodeData::SerialNumberBarcodeData(const std::wstring& data)
{
	if (!ValidateFormat(data))
		_barcodeData = L"";
	else
		_barcodeData = data;
}


SerialNumberBarcodeData::~SerialNumberBarcodeData()
{
}


bool SerialNumberBarcodeData::ValidateFormat(const std::wstring& data)
{
	return std::regex_match(data, BarcodeFormat);
}


const std::wstring SerialNumberBarcodeData::GetModelCode() const
{
	std::wsmatch subMatch;
	if (std::regex_search(_barcodeData, subMatch, BarcodeFormat))
		return subMatch[static_cast<std::wsmatch::size_type>(MatchingPart::ModelCode)].str();
	else
		return std::wstring();
}


const std::wstring SerialNumberBarcodeData::GetSerialNumber() const
{
	std::wsmatch subMatch;
	if (std::regex_search(_barcodeData, subMatch, BarcodeFormat))
		return subMatch[static_cast<std::wsmatch::size_type>(MatchingPart::SerialNumber)].str();
	else
		return std::wstring();
}


const std::wstring SerialNumberBarcodeData::Get() const
{
	return _barcodeData;
}
