
// MfcAppDoc.cpp : implementation of the CMfcAppDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MfcApp.h"
#endif

#include "MfcAppDoc.h"
#include <propkey.h>
#include "AppMessages.h"
#include "Entities/InspectionResultImpl.h"
#include <memory>

#include "Entities/Fakes/InspectionResultImplFake.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMfcAppDoc

IMPLEMENT_DYNCREATE(CMfcAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CMfcAppDoc, CDocument)
END_MESSAGE_MAP()


// CMfcAppDoc construction/destruction

CMfcAppDoc::CMfcAppDoc() noexcept
	:m_BarcodeData(L"")
{
	m_InspectionResult = new InspectionResultImpl();
}

CMfcAppDoc::~CMfcAppDoc()
{
	if(m_InspectionResult!=NULL)
	{
		delete m_InspectionResult;
		m_InspectionResult = NULL;
	}
}

BOOL CMfcAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}


// CMfcAppDoc serialization

void CMfcAppDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMfcAppDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMfcAppDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMfcAppDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl* pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMfcAppDoc diagnostics

#ifdef _DEBUG
void CMfcAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMfcAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMfcAppDoc commands


void CMfcAppDoc::SetSerialNumberBarcode(const std::wstring& value)
{
	m_BarcodeData = SerialNumberBarcodeData(value);

	PostMessageToAllViews(static_cast<UINT>(AppMessages::WM_BARCODE_DATA_CHANGED));
}

void CMfcAppDoc::PostMessageToAllViews(UINT message)
{
	PostMessageToAllViews(message, 0, 0);
}

void CMfcAppDoc::PostMessageToAllViews(UINT message, WPARAM wParam, LPARAM lParam)
{
	auto pos = GetFirstViewPosition();
	while (pos!=NULL)
	{
		auto view = GetNextView(pos);
		auto hwnd = view->GetSafeHwnd();
		::PostMessage(hwnd, message, wParam, lParam);
	}
}

const std::wstring CMfcAppDoc::GetModelCode()
{
	return m_BarcodeData.GetModelCode();
}

const std::wstring CMfcAppDoc::GetSerialNumber()
{
	return m_BarcodeData.GetSerialNumber();
}


void CMfcAppDoc::ExecuteInspection()
{
	// TODO: Add your implementation code here.
	delete m_InspectionResult;
	m_InspectionResult = new InspectionResultImplFake();
}

InspectionResult* CMfcAppDoc::GetInspectionResult()
{
	//return static_cast<InspectionResult*>(m_InspectionResult);
	return m_InspectionResult;
}
