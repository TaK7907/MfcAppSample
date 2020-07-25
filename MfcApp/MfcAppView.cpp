
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
#include "Helpers/WindowTextAccessor.h"
#include "ValueObjects/SerialNumberBarcodeData.h"
#include "AppMessages.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMfcAppView

IMPLEMENT_DYNCREATE(CMfcAppView, CFormView)

BEGIN_MESSAGE_MAP(CMfcAppView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMfcAppView::OnBnClickedButton1)
	ON_MESSAGE(static_cast<int>(AppMessages::WM_BARCODE_DATA_CHANGED), &CMfcAppView::OnBarcodeDataChanged)
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

	SetResultListStyle();
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
	BarcodeInputDialog dlg;
	auto r = dlg.DoModal();
	if (r != IDOK) return;

	ClearInspectionResultList();

	auto barcode = dlg.GetBarcode();
	auto doc = GetDocument();
	doc->SetSerialNumberBarcode(barcode.GetString());

	doc->ExecuteInspection();

	ShowInspectionResult(doc->GetInspectionResult());
}

void CMfcAppView::ShowInspectionResult(const InspectionResult * result)
{
	ShowInspectionResultItem(L"Width", result->GetWidth(), result->GetWidthJudgeResult());
	ShowInspectionResultItem(L"Height", result->GetHeight(), result->GetHeightJudgeResult());
	auto v = result->GetPerpendicularity();
	auto r = result->GetPerpendicularityJudgeResult();
	ShowInspectionResultItem(L"Perpendicularity", v, r);
}

void CMfcAppView::ShowInspectionResultItem(const wchar_t* name, const wchar_t* value, const wchar_t* result)
{
	auto list = static_cast<CListCtrl*>(GetDlgItem(IDC_LIST_RESULT));
	auto n = list->GetItemCount();

	list->InsertItem(n, name);
	list->SetItemText(n, 1, value);
	list->SetItemText(n, 2, result);
}

void CMfcAppView::SetText(const int nID, const CString& text)
{
	WindowTextAccessor::SetText(this, nID, text);
}

LRESULT CMfcAppView::OnBarcodeDataChanged(WPARAM wParam, LPARAM lParam)
{
	auto doc = GetDocument();

	SetText(IDC_EDIT_MODELCODE, doc->GetModelCode().c_str());
	SetText(IDC_EDIT_SERIALNUMBER, doc->GetSerialNumber().c_str());

	return 0;
}

void CMfcAppView::ClearInspectionResultList()
{
	auto list = static_cast<CListCtrl*>(GetDlgItem(IDC_LIST_RESULT));
	list->DeleteAllItems();
}

int CMfcAppView::SetResultListStyle()
{
	auto list = static_cast<CListCtrl*>(GetDlgItem(IDC_LIST_RESULT));
	list->ModifyStyle(0, LVS_REPORT);
	list->SetExtendedStyle(LVS_EX_FULLROWSELECT);

	CRect clientRect;
	list->GetClientRect(clientRect);
	constexpr int numOfColumns = 3;
	const int columnWidth = clientRect.Width() / numOfColumns;

	list->InsertColumn(0, L"Item", LVCFMT_LEFT, columnWidth, 0);
	list->InsertColumn(1, L"Measure", LVCFMT_RIGHT, columnWidth, 1);
	list->InsertColumn(2, L"Result", LVCFMT_CENTER, columnWidth, 2);

	return 0;
}
