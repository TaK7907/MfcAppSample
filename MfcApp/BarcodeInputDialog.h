#pragma once


// BarcodeInputDialog dialog

class BarcodeInputDialog : public CDialogEx
{
	DECLARE_DYNAMIC(BarcodeInputDialog)

public:
	BarcodeInputDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~BarcodeInputDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BARCODE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();

private:
	CString m_barcode;
public:
	const CString& GetBarcode();
	afx_msg void OnEnChangeEditBarcode();
};
