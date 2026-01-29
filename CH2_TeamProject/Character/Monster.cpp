#include "Monster.h"
#include "Character.h"
#include <iostream>
using namespace std;


AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
}

FDamageSet AMonster::Attack(ACharacter* Target)
{
	
	FDamageSet Result = ACharacter::Attack(Target);
	string DamageText = "물어 뜯었습니다.";
	if (Result.BCritcal)
	{
		DamageText = "치명적인 먹방을 했습니다.";
	}

	cout << Name << DamageText << "대미지 :  " << Result.FDamage << endl;
	cout << Name << "가 " << Result.FDamage << "의 피해를 입었습니다." << endl;
	return Result;
}
