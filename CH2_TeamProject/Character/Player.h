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
	void LevelUp();
	void UseItem();
};
