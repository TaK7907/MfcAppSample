#include "../pch.h"
#include "WindowTextAccessor.h"
#include <afx.h>
#include <stdexcept>

void WindowTextAccessor::SetText(const CWnd * wnd, const int id, const CString& text)
{
    if (wnd == NULL)
        throw std::logic_error("wnd was null.");

    auto ctrl = wnd->GetDlgItem(id);
    if (ctrl == NULL)
        throw std::logic_error("invalid id.");

    ctrl->SetWindowTextW(text);
}


const CString WindowTextAccessor::GetText(const CWnd* wnd, const int id)
{
    if (wnd == NULL)
        throw std::logic_error("wnd was null.");

    auto ctrl = wnd->GetDlgItem(id);
    if (wnd == NULL)
        throw std::logic_error("invalid id.");

    CString retVal;
    ctrl->GetWindowTextW(retVal);

    return retVal;
}
