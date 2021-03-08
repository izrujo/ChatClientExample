#include "ConnectSocket.h"
#include "ChatClientDialog.h"

ConnectSocket::ConnectSocket() {

}

ConnectSocket::~ConnectSocket() {

}

void ConnectSocket::OnClose(int nErrorCode) {
	ShutDown();
	Close();

	CSocket::OnClose(nErrorCode);

	AfxMessageBox(_T("Error : Disconnected from server!"));
	::PostQuitMessage(0);
}

void ConnectSocket::OnReceive(int nErrorCode) {
	TCHAR buffer[1024];
	::ZeroMemory(buffer, sizeof(buffer));

	if (Receive(buffer, sizeof(buffer)) > 0) {
		ChatClientDialog* main = (ChatClientDialog*)AfxGetMainWnd();
		main->list.AddString(buffer);
		main->list.SetCurSel(main->list.GetCount() - 1);
	}

	CSocket::OnReceive(nErrorCode);
}