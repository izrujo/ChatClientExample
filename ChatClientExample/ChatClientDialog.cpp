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
	///////
	this->socket.Create();
	//IP주소 : 서버 라우터의 공용 IP주소, 포트번호 : 포트포워딩 규칙 설정 시 설정한 서버의 외부 포트 번호
	if (this->socket.Connect(_T("192.168.0.13"), 63379) == FALSE)
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
		this->message.GetLength());

	this->message = _T("");
	UpdateData(FALSE);
}