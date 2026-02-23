#pragma once
#include "USkill.h"

class UPlayerHealing : public USkill
{

public:
	UPlayerHealing(ACharacter* Owner);

	void Play(ACharacter* Target) override;
};

