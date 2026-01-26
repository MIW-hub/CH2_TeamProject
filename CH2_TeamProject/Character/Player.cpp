#include "Player.h"
#include <iostream>


using namespace std;
APlayer::APlayer(const string& NewName, FUnitStat& NewStat)
	: ACharacter(NewName,NewStat)
{
	MaxLevel = 10;
	Level = 1;
	Exp = 0 ;
}

APlayer::~APlayer()
{
}


void APlayer::Status(ACharacter* player)
{
	cout << " 이름 : " << player->GetName() << " 레벨 : " << Level << " 경험치 : "
		<< Exp << " 공격력 : " << player->GetAtk() << " 방어력 : " << player->GetDef()
		<< " 치명타 : " << player->GetCri() << "% " << endl;
}

void APlayer::LevelUp()
{
}

void APlayer::UseItem()
{
}

