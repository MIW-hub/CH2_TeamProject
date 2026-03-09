#pragma once

#include "Character.h"

using namespace std;

class APlayer : public ACharacter
{
public:
	APlayer(const string& NewName, FUnitStat& Stat);
	~APlayer() override;

protected:
	int Level;
	int Exp;
	
public:
	string DamageText;
	void LevelUp();
	void UseItem();
	void PlayTurn(ACharacter* Target) override;
};
