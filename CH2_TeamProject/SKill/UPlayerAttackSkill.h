#pragma once
#include "USkill.h"

class UPlayerAttackSkill : public USkill
{
public:
	UPlayerAttackSkill(ACharacter* Owner);

	void Play(ACharacter* Target) override;
};

