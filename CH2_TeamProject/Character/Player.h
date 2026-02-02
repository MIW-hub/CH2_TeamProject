#pragma once

#include "Character.h"

using namespace std;

class APlayer : public ACharacter
{
public:
	APlayer(const string& NewName, FUnitStat& Stat);

protected:
	int Level;
	int Exp;
	
public:
	/*void LogStatus(ACharacter* player);*/
	string DamageText;
	void LevelUp();
	void UseItem();
	FDamageResult Attack(ACharacter* target) override;
	void UseSkill(ACharacter* Target);
};
