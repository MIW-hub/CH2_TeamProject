#include "Player.h"
#include <iostream>


using namespace std;

APlayer::APlayer(const string& NewName, FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
}

//void APlayer::LogStatus(ACharacter* player)
//{
//	cout << " 이름 : " << player->GetName()
//		<< " 레벨 : " << Level
//		<< " 경험치 : " << Exp
//		<< " 공격력 : " << player->GetAtk()
//		<< " 방어력 : " << player->GetDef()
//		<< " 치명타 : " << player->GetCri()
//		<< "% " << endl;
//}

void APlayer::LevelUp()
{
	//나중에 여기서 쓰다가 -> 다른데서도 쓸일이 있으면
	// APlayer 헤더나 다른 헤더파일로 옮김.
	constexpr int MAX_LEVEL = 10;


}

void APlayer::UseItem()
{
}

FDamageResult APlayer::Attack(ACharacter* target)
{
	
	FDamageResult Result = ACharacter::Attack(target);

	DamageText = "가 공격합니다!";
	if (Result.BCritcal)
	{
		
		DamageText = "헤드샷";
	}

	/*cout << Name << DamageText << "대미지 :  " << Result.FDamage << endl;
	cout << Name << "가 " << set.FDamage << "의 피해를 입었습니다." << endl;
	cout << target->GetName() << "의 HP:  " << target->GetHp()<< endl;
	cout << target->GetName() << "의 MP:  " << target->GetMp()<< endl;*/

	Result.PrintMessage(DamageText);
	return Result;
}
void APlayer::UseSkill(ACharacter* Target)
{
	if (Stat.Mp < 10) {
		cout << "MP가 부족합니다." << endl;
		return;
	}


	
	int Damage = Stat.Atk * 2.0f;
	int FinalDamage = Target->TakeDamage(Damage);
	Stat.Mp -= 10;
	/*cout << Name << "의 MP:  " << Stat.Mp << endl;
	cout << "회심의 일격!" << endl;*/
	FDamageResult Result;

	Result.FDamage = FinalDamage;
	Result.Attacker = this;
	Result.Target = Target;
	Result.BCritcal = false;


	Result.PrintMessage(DamageText);
}
