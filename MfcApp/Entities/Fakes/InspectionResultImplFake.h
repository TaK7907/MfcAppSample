#pragma once

#include "../InspectionResult.h"

class InspectionResultImplFake :
    public InspectionResult
{
public:
    InspectionResultImplFake();
    virtual ~InspectionResultImplFake();

    // Inherited via InspectionResult
    virtual wchar_t* GetHeight() const override;
    virtual wchar_t* GetWidth() const override;
    virtual wchar_t* GetPerpendicularity() const override;
    virtual wchar_t* GetHeightJudgeResult() const override;
    virtual wchar_t* GetWidthJudgeResult() const override;
    virtual wchar_t* GetPerpendicularityJudgeResult() const override;
};

