#include "Monster.h"
#include "Character.h"
#include <iostream>
using namespace std;


AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
}

FDamageResult AMonster::Attack(ACharacter* Target)
{
	FDamageResult Result = ACharacter::Attack(Target);
	
	DamageText = " 물어 뜯었습니다.";
	if (Result.BCritcal)
	{
		DamageText = " 이 치명적인 먹방을 했습니다.";
	}

	
	Result.PrintMessage(DamageText);

	return Result;
}
void AMonster::UseSkill(ACharacter* Target)
{
	
	if (Stat.Mp < 10) {
		cout << "MP가 부족합니다." << endl;
		return;
	}	
	Stat.Mp -= 10;
	int Damage = Stat.Atk;
	int FinalDamage = Target->TakeDamage(Damage);


	
	DamageText = " 흡혈(Vampire)! ";
	

	FDamageResult Result;

	Result.FDamage = FinalDamage;
	Result.Attacker = this;
	Result.Target = Target;
	Result.BCritcal = false;

	Result.PrintMessage(DamageText);
	Heal(FinalDamage);
}