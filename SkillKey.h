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
	std::string m_KeySequence;//记录按键序列 ;
	std::vector<int> m_SkillIDList;//记录该按键序列下所有的技能ID值。例如站A，蹲A，跳A，前A ;

};

#endif