#pragma once
#include "USkill.h"

class UMonsterDempseyRollSkill : public USkill
{

public:
	UMonsterDempseyRollSkill(ACharacter* Owner);

	void Play(ACharacter* Target) override;
};

