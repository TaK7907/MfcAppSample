#pragma once
class WindowTextAccessor
{
public:
	static void SetText(const CWnd * wnd, const int id, const CString& text);
	static const CString GetText(const CWnd* wnd, const int id);
};

