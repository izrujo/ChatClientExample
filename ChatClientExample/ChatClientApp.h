#ifndef _CHATCLIENTAPP_H
#define _CHATCLIENTAPP_H

#include <afxwinappex.h>

class ChatClientApp : public CWinAppEx {
public:
	ChatClientApp();

public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

extern ChatClientApp chatClientApp;

#endif //_CHATCLIENTAPP_H