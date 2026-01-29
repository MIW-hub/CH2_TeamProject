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

FDamageSet APlayer::Attack(ACharacter* target)
{
	FDamageSet Result = ACharacter::Attack(target);
	string DamageText = "가 공격합니다!";
	if (Result.BCritcal)
	{
		DamageText = "가 치명적인 공격합니다!";
	}

	cout << Name << DamageText << "대미지 :  " <<Result.FDamage << endl;
	cout << Name << "가 " << Result.FDamage << "의 피해를 입었습니다." << endl;
	return Result;
}
