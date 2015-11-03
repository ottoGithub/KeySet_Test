#include "stdafx.h"
#include "KeySet_Test.h"
#include "KeySetSystem.h"

KeySetManager::KeySetManager()
{
	m_nTotalTime = 0;
}

void KeySetManager::KeyEvent(int nKeyCode, int nKeyType)
{

}

void KeySetManager::Tick(int nTime)
{
	if(!m_strKeySeq.empty())
	{
		//GetKeyState()
	}
	ShowKeySeqText();
}

char* KeySetManager::GetVirtualKey(int nKeyCode)
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
		return "6";
	case KeyA:
		return "A";
	case KeyB:
		return "B";
	}
	return "-";
}

void KeySetManager::ShowKeySeqText()
{
	//wchar_t * wc = new wchar_t[str.size()];
	//swprintf(wc,L"%S",str.c_str()); //注意大写S。
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

void KeySetManager::InitVirtualKeyList()
{
	m_VirKeyList.push_back(new KeyState(VK_UP,false));
	m_VirKeyList.push_back(new KeyState(VK_DOWN,false));
	m_VirKeyList.push_back(new KeyState(VK_LEFT,false));
	m_VirKeyList.push_back(new KeyState(VK_RIGHT,false));
	m_VirKeyList.push_back(new KeyState(VK_NUMPAD1,false));
	m_VirKeyList.push_back(new KeyState(VK_NUMPAD2,false));
}

void KeySetManager::InitAllKeySequence()
{
	//以八神A键相关技能距离
	m_AllKeySequence.push_back(new SkillKey("A"));
	m_AllKeySequence.push_back(new SkillKey("6A"));
	m_AllKeySequence.push_back(new SkillKey("26A"));//暗勾手
	m_AllKeySequence.push_back(new SkillKey("62A"));//葵花
	m_AllKeySequence.push_back(new SkillKey("426A"));//抓
	m_AllKeySequence.push_back(new SkillKey("626A"));//升龙
	m_AllKeySequence.push_back(new SkillKey("2624A"));//八稚女
	m_AllKeySequence.push_back(new SkillKey("2426A"));//八酒杯
}