#pragma once
#include <string>
#include "Character.h"

using namespace std;


class AMonster : public ACharacter
{
public:
	AMonster(const string& name, const FUnitStat& NewStat);
	FDamageResult Attack(ACharacter* Target) override;
	void UseSkill(ACharacter* Target);
};
