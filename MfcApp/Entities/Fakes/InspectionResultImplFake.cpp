#include "InspectionResultImplFake.h"

InspectionResultImplFake::InspectionResultImplFake()
{
}

InspectionResultImplFake::~InspectionResultImplFake()
{
}

wchar_t*InspectionResultImplFake::GetHeight() const
{
	return L"1200.45mm";
}

wchar_t*InspectionResultImplFake::GetWidth() const
{
	return L"689.92mm";
}

wchar_t*InspectionResultImplFake::GetPerpendicularity() const
{
	return L"0.02mm";
}

wchar_t*InspectionResultImplFake::GetHeightJudgeResult() const
{
	return L"OK";
}

wchar_t*InspectionResultImplFake::GetWidthJudgeResult() const
{
	return L"NG";
}

wchar_t*InspectionResultImplFake::GetPerpendicularityJudgeResult() const
{
	return L"OK";
}
