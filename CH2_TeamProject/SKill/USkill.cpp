#include "USkill.h"
#include "../Character/Character.h"


USkill::USkill(ACharacter* Owner, string NewSkillName, int NewMpCost)
{
	this->Owner = Owner; 
	SkillName = NewSkillName;
	MpCost = NewMpCost;
}
