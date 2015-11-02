#ifndef _KEYSET_SYSTEM_H_
#define _KEYSET_SYSTEM_H_
#include "Singleton.h"
#include "KeyDefine.h"

#include <string>

class KeySetManager : public Singleton<KeySetManager>
{
public:
	KeySetManager();
	void KeyEvent(int nKeyCode, int nKeyType);

	void Tick(int nTime);

	void ShowKeySeqText();
protected:
	char* GetVirtualKey(int nKeyCode, int nKeyType);
private:
	std::string m_strKeySeq;
	int m_nTotalTime;
};
#endif