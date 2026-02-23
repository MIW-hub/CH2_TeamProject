#pragma once
#include "USkill.h"

class UMonsterAttackSkill : public USkill
{
public:
	UMonsterAttackSkill(ACharacter* Owner);

	void Play(ACharacter* Target) override;
};

