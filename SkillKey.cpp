#include "stdafx.h"
#include "SkillKey.h"

SkillKey::SkillKey(const char* KeySequence):m_KeySequence(KeySequence)
{
	m_nStep = Step_Wait;
	LoadSkillIDByKey(KeySequence);
}

void SkillKey::LoadSkillIDByKey(const char* KeySequence)
{

}