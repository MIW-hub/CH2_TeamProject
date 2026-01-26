#pragma once

#include "Character.h"

using namespace std;

class APlayer : public ACharacter
{
	// 멤버 변수: Level, Exp
	// 멤버 함수: LevelUp(), UseItem() - 함수는 빈 구현으로...
public:
	APlayer(const string& NewName,FUnitStat& Stat);
	virtual ~APlayer();
	 
protected:
	int Level;
	int MaxLevel;
	int Exp;
	

public:
	
	void Status(ACharacter* player);
	void LevelUp();
	void UseItem();
};

