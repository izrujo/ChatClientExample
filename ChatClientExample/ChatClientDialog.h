#ifndef _CHATCLIENTDIALOG_H
#define _CHATCLIENTDIALOG_H

#include <afxwin.h>
#include "resource.h"
#include "ConnectSocket.h"

class ChatClientDialog : public CDialog {
public:
	enum { IDD = IDD_CHATCLIENTDIALOG };
public:
	ChatClientDialog(CWnd* parent = NULL);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	ConnectSocket socket;
	CListBox list;
	CString message;
	afx_msg void OnSendButtonClicked();

};

#endif //_CHATCLIENTDIALOG_H