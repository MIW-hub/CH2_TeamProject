#include "UMonsterDrainSkill.h"
#include "../Character/Character.h"
#include <string>

UMonsterDrainSkill::UMonsterDrainSkill(ACharacter* Owner) : USkill(Owner,"흡혈",20)
{
}

void UMonsterDrainSkill::Play(ACharacter* Target)
{
	int Damage = Owner->GetAtk();
	int FinalDamage = Target->TakeDamage(Damage);

	string DamageText = " 흡혈(Vampire)! ";

	FDamageResult Result;

	Result.FDamage = FinalDamage;
	Result.Attacker = Owner;
	Result.Target = Target;
	Result.BCritcal = false;

	Result.PrintMessage(DamageText);
	Owner->Heal(FinalDamage);

}
