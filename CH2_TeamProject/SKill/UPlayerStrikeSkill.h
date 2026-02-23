#pragma once
#include "USkill.h"

class UPlayerStrikeSkill : public USkill
{
	UPlayerStrikeSkill(ACharacter* Owner);

	void Play(ACharacter* Target) override;

};

