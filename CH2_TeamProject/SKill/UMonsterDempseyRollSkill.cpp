#include "UMonsterDempseyRollSkill.h"
#include "../Character/Character.h"
#include <iostream>
#include <string>

using namespace std;
UMonsterDempseyRollSkill::UMonsterDempseyRollSkill(ACharacter* Owner) : USkill(Owner)
{
}

void UMonsterDempseyRollSkill::Play(ACharacter* Target)
{
	int Damage = Owner->GetAtk();
	int FinalDamage = Target->TakeDamage(Damage);
	int DempseyRoll = 0;
	while (Owner->GetRandomInt() > 30 || DempseyRoll == 5)
	{
		Damage *= Owner->GetAtk();
		DempseyRoll++;
	}
	

	string DamageText = "DempseyRoll";
	DamageText += to_string(DempseyRoll) + "번 공격했습니다. ";
	FDamageResult Result;

	Result.FDamage = FinalDamage;
	Result.Attacker = Owner;
	Result.Target = Target;
	Result.BCritcal = false;


	Result.PrintMessage(DamageText);

}
