#include "UPlayerStrikeSkill.h"
#include "../Character/Character.h"
#include "iostream"


UPlayerStrikeSkill::UPlayerStrikeSkill(ACharacter* Owner) : USkill(Owner)
{

}
void UPlayerStrikeSkill::Play(ACharacter* Target)
{

	int Damage = Owner->GetAtk()* 2.0f;
	int FinalDamage = Target->TakeDamage(Damage);

	/*cout << Name << "의 MP:  " << Stat.Mp << endl;*/
	string DamageText = "뚝베기 사냥 !";
	FDamageResult Result;

	Result.FDamage = FinalDamage;
	Result.Attacker = Owner;
	Result.Target = Target;
	Result.BCritcal = false;


	Result.PrintMessage(DamageText);

}
