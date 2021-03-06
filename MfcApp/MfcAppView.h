
// MfcAppView.h : interface of the CMfcAppView class
//

#pragma once


class CMfcAppView : public CFormView
{
protected: // create from serialization only
	CMfcAppView() noexcept;
	DECLARE_DYNCREATE(CMfcAppView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPP_FORM };
#endif

// Attributes
public:
	CMfcAppDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CMfcAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void ShowInspectionResult(const InspectionResult * result);
	void ShowInspectionResultItem(const wchar_t* name, const wchar_t* value, const wchar_t* result);
private:
	void SetText(const int nID, const CString& text);
//	void OnBarcodeDataChangedOrig();
protected:
	afx_msg LRESULT OnBarcodeDataChanged(WPARAM wParam, LPARAM lParam);
	void ClearInspectionResultList();
public:
	int SetResultListStyle();
};

#ifndef _DEBUG  // debug version in MfcAppView.cpp
inline CMfcAppDoc* CMfcAppView::GetDocument() const
   { return reinterpret_cast<CMfcAppDoc*>(m_pDocument); }
#endif

