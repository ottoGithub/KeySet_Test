#ifndef _SKILL_KEY_H_
#define _SKILL_KEY_H_
#include <string>
#include <vector>
enum eKeyStep
{
	Step_Wait = 0,
	Step_Press,
	Step_Hesitate,
};

class SkillKey
{
public:
	SkillKey(const char* KeySequence);
private:
	void LoadSkillIDByKey(const char* KeySequence);

private:
	int m_nStep;
	std::string m_KeySequence;//��¼�������� ;
	std::vector<int> m_SkillIDList;//��¼�ð������������еļ���IDֵ������վA����A����A��ǰA ;

};

#endif