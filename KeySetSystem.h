#ifndef _KEYSET_SYSTEM_H_
#define _KEYSET_SYSTEM_H_
#include "Singleton.h"
#include "KeyDefine.h"
#include "SkillKey.h"

#include <string>
#include <vector>


struct KeyState
{
	KeyState(int n, bool b)
	{
		bPress = b;
		nVKCode = n;
	}
	bool bPress;
	int nVKCode;
};

class KeySetManager : public Singleton<KeySetManager>
{
public:
	KeySetManager();
	void KeyEvent(int nKeyCode, int nKeyType);

	void Tick(int nTime);

	void ShowKeySeqText();
protected:
	char* GetVirtualKey(int nKeyCode);

	void InitVirtualKeyList();
	void InitAllKeySequence();
private:
	std::string m_strKeySeq;
	int m_nTotalTime;
	std::vector<KeyState*> m_VirKeyList;
	std::vector<SkillKey*> m_AllKeySequence;
};
#endif