#include "Monster.h"
#include "Character.h"
#include <iostream>
using namespace std;


AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
}

void AMonster::Attack(ACharacter* Target)
{
	int Damage = Stat.Atk;
	cout << Target->GetName() << "을 물어" << Damage << "를 입혔습니다." << endl;
	Target->TakeDamage(Damage);
}
