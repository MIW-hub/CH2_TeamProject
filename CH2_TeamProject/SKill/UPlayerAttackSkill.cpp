#include "UPlayerAttackSkill.h"
#include "../Character/Character.h"

using namespace std;

UPlayerAttackSkill::UPlayerAttackSkill(ACharacter* Owner) : USkill(Owner)
{

}

void UPlayerAttackSkill::Play(ACharacter* Target)
{
	int Damage = Owner->GetAtk();
	bool BCritcal = Owner->GetRandomInt() <= Owner->GetCri();

	if (BCritcal)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}

	int FinalDamage = Target->TakeDamage(Damage);

	FDamageResult Result;

	Result.FDamage = FinalDamage;
	Result.Attacker = Owner;
	Result.Target = Target;
	Result.BCritcal = BCritcal;

	string DamageText;
	DamageText = "가 공격합니다!";
	if (Result.BCritcal)
	{

		DamageText = "헤드샷";
	}

	Result.PrintMessage(DamageText);
}
