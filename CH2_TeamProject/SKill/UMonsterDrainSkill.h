#pragma once
#include "USkill.h"

class UMonsterDrainSkill : public USkill
{
public:
	UMonsterDrainSkill(ACharacter* Owner);

	void Play(ACharacter* Target) override;
	
};

