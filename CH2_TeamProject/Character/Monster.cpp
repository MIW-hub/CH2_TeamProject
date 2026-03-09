#include "Monster.h"
#include "Character.h"
#include "../SKill/UMonsterDrainSkill.h"
#include "../SKill/UMonsterAttackSkill.h"
#include "../SKill/UMonsterDempseyRollSkill.h"
#include <iostream>

using namespace std;


AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Skills.push_back(make_unique<UMonsterAttackSkill>(this));
	Skills.push_back(make_unique<UMonsterDrainSkill>(this));
	Skills.push_back(make_unique<UMonsterDempseyRollSkill>(this));
	
}

AMonster::~AMonster()
{
}

void AMonster::PlayTurn(ACharacter* Target)
{
	int index = Target->GetRandomInt(Skills.size());
	Skills[index]->Play(Target);
}
