#include "stdafx.h"
#include "KeySet_Test.h"
#include "KeySetSystem.h"

KeySetManager::KeySetManager()
{
	m_nTotalTime = 0;
}

void KeySetManager::KeyEvent(int nKeyCode, int nKeyType)
{
	m_strKeySeq += GetVirtualKey(nKeyCode,nKeyType);
	m_nTotalTime = 0;
}

void KeySetManager::Tick(int nTime)
{
	m_nTotalTime += nTime;
	if(m_nTotalTime > 1000)
	{
		m_nTotalTime = 0;
		m_strKeySeq.clear();
		//ShowKeySeqText();
	}
	ShowKeySeqText();
}

char* KeySetManager::GetVirtualKey(int nKeyCode, int nKeyType)
{
	if(nKeyType == KeyType_Down)
	{
		switch(nKeyCode)
		{
		case KeyUp:
			return "8";
		case KeyDown:
			return "2";
		case KeyLeft:
			return "4";
		case KeyRight:
			return "8";
		case KeyA:
			return "A";
		case KeyB:
			return "B";
		}
	}
	return "-";
}

void KeySetManager::ShowKeySeqText()
{
	//wchar_t * wc = new wchar_t[str.size()];
	//swprintf(wc,L"%S",str.c_str()); //×¢Òâ´óÐ´S¡£
	RECT rect;
	TCHAR *buf = new TCHAR[m_strKeySeq.size()+1];
	swprintf_s(buf,m_strKeySeq.size()+1,L"%S",m_strKeySeq.c_str());
	GetClientRect (g_hWnd, &rect) ;
	//rect.top = long(rect.bottom*0.5);
	rect.right = long(rect.right);
	rect.bottom = long(rect.bottom);

	OutPutText(g_hWnd,buf,rect);
	delete buf;
}