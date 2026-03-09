#include "UMonsterAttackSkill.h"
#include "../Character/Character.h"

using namespace std;


UMonsterAttackSkill::UMonsterAttackSkill(ACharacter* Owner) : USkill(Owner,"공격",0)
{
}

void UMonsterAttackSkill::Play(ACharacter* Target)
{
	int Damage = Owner->GetAtk();
	bool BCritcal = Owner->GetRandomInt(100) <= Owner->GetCri();

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
	DamageText = " 물어 뜯었습니다.";
	if (Result.BCritcal)
	{
		DamageText = " 이 치명적인 먹방을 했습니다.";
	}

	Result.PrintMessage(DamageText);
}


