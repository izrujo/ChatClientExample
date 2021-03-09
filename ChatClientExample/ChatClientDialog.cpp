#include "ChatClientDialog.h"

BEGIN_MESSAGE_MAP(ChatClientDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &ChatClientDialog::OnSendButtonClicked)
END_MESSAGE_MAP()

ChatClientDialog::ChatClientDialog(CWnd* parent) 
	: CDialog(IDD, parent) {

}

void ChatClientDialog::DoDataExchange(CDataExchange* pDX) {
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHATLIST, this->list);
	DDX_Text(pDX, IDC_EDIT_CHAT, this->message);
}

BOOL ChatClientDialog::OnInitDialog() {
	CDialog::OnInitDialog();

	this->socket.Create();
	if (this->socket.Connect(_T("192.168.0.12"), 63620) == FALSE)
	{
		AfxMessageBox(_T("ERROR: Failed to connect server"));
		PostQuitMessage(0);

		return FALSE;
	}

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void ChatClientDialog::OnSendButtonClicked()
{
	UpdateData(TRUE);
	this->socket.Send((LPVOID)(LPCTSTR)this->message,
		this->message.GetLength() * 2);

	this->message = _T("");
	UpdateData(FALSE);
}