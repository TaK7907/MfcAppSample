#pragma once

#include <string>

class InspectionResult
{
public:
	virtual wchar_t* GetHeight() const = 0;
	virtual wchar_t* GetWidth() const = 0;
	virtual wchar_t* GetPerpendicularity() const = 0;
	virtual wchar_t* GetHeightJudgeResult() const = 0;
	virtual wchar_t* GetWidthJudgeResult() const = 0;
	virtual wchar_t* GetPerpendicularityJudgeResult() const = 0;
};

