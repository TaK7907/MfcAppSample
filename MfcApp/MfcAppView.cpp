
// MfcAppView.cpp : implementation of the CMfcAppView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MfcApp.h"
#endif

#include "MfcAppDoc.h"
#include "MfcAppView.h"
#include "BarcodeInputDialog.h"
#include "utilities/WindowTextAccessor.h"
#include "ValueObjects/SerialNumberBarcodeData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcAppView

IMPLEMENT_DYNCREATE(CMfcAppView, CFormView)

BEGIN_MESSAGE_MAP(CMfcAppView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMfcAppView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMfcAppView construction/destruction

CMfcAppView::CMfcAppView() noexcept
	: CFormView(IDD_MFCAPP_FORM)
{
	// TODO: add construction code here

}

CMfcAppView::~CMfcAppView()
{
}

void CMfcAppView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CMfcAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMfcAppView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMfcAppView diagnostics

#ifdef _DEBUG
void CMfcAppView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMfcAppView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMfcAppDoc* CMfcAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMfcAppDoc)));
	return (CMfcAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CMfcAppView message handlers


void CMfcAppView::OnBnClickedButton1()
{
	auto doc = GetDocument();
	doc->SetBarcode(L"");

	SetText(IDC_EDIT_MODELCODE, doc->GetModelCode().c_str());
	SetText(IDC_EDIT_SERIALNUMBER, doc->GetSerialNumber().c_str());

	BarcodeInputDialog dlg;
	auto r = dlg.DoModal();
	
	if (r == IDOK)
	{
		auto barcode = dlg.GetBarcode();

		doc->SetBarcode(barcode.GetString());
		SetText(IDC_EDIT_MODELCODE, doc->GetModelCode().c_str());
		SetText(IDC_EDIT_SERIALNUMBER, doc->GetSerialNumber().c_str());


	}
}


void CMfcAppView::SetText(const int nID, const CString& text)
{
	WindowTextAccessor::SetText(this, nID, text);
}
