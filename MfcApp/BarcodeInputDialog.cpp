// BarcodeInputDialog.cpp : implementation file
//

#include "pch.h"
#include "MfcApp.h"
#include "BarcodeInputDialog.h"
#include "afxdialogex.h"
#include "Helpers/WindowTextAccessor.h"
#include "ValueObjects/SerialNumberBarcodeData.h"

// BarcodeInputDialog dialog

IMPLEMENT_DYNAMIC(BarcodeInputDialog, CDialogEx)

BarcodeInputDialog::BarcodeInputDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BARCODE, pParent)
{

}

BarcodeInputDialog::~BarcodeInputDialog()
{
}

void BarcodeInputDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BarcodeInputDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &BarcodeInputDialog::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT_BARCODE, &BarcodeInputDialog::OnEnChangeEditBarcode)
END_MESSAGE_MAP()


// BarcodeInputDialog message handlers


void BarcodeInputDialog::OnBnClickedOk()
{
	m_barcode = WindowTextAccessor::GetText(this, IDC_EDIT_BARCODE);

	CDialogEx::OnOK();
}

const CString& BarcodeInputDialog::GetBarcode()
{
	return m_barcode;
}


void BarcodeInputDialog::OnEnChangeEditBarcode()
{
	const CString barcode = WindowTextAccessor::GetText(this, IDC_EDIT_BARCODE);

	if (SerialNumberBarcodeData::ValidateFormat(barcode.GetString()))
	{
		GetDlgItem(IDOK)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDOK)->EnableWindow(FALSE);
	}
}
