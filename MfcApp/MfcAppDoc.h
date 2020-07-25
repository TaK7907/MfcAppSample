
// MfcAppDoc.h : interface of the CMfcAppDoc class
//
#include "ValueObjects/SerialNumberBarcodeData.h"

#pragma once

class CMfcAppDoc : public CDocument
{
protected: // create from serialization only
	CMfcAppDoc() noexcept;
	DECLARE_DYNCREATE(CMfcAppDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CMfcAppDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS

private:
	SerialNumberBarcodeData m_BarcodeData;
public:
	void SetSerialNumberBarcode(const std::wstring& value);
	void PostMessageToAllViews(UINT message);
	void PostMessageToAllViews(UINT message, WPARAM wParam, LPARAM lParam);
	const std::wstring GetModelCode() const;
	const std::wstring GetSerialNumber() const;
};
