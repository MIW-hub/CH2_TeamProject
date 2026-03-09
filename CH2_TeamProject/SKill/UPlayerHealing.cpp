#include "UPlayerHealing.h"
#include "../Character/Character.h"
#include <iostream>

using namespace std;

UPlayerHealing::UPlayerHealing(ACharacter* Owner) : USkill(Owner,"힐링",20)
{
}

void UPlayerHealing::Play(ACharacter* Target)
{
	string DamageText = " 힐!!!! ";

	FDamageResult Result;

	Result.FDamage = 0;
	Result.Attacker = Owner;
	Result.Target = Target;
	Result.BCritcal = false;

	Result.PrintMessage(DamageText);
	Owner->Heal(Owner->GetAtk()* 1.5);

}
