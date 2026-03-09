#include "Player.h"
#include <iostream>
#include "../SKill/UPlayerHealing.h"
#include "../SKill/UPlayerStrikeSkill.h"
#include "../SKill/UPlayerAttackSkill.h"
#include "../Skill/USkill.h"

using namespace std;

APlayer::APlayer(const string& NewName, FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
	
	Skills.push_back(make_unique<UPlayerAttackSkill>(this));
	Skills.push_back(make_unique<UPlayerHealing>(this));
	Skills.push_back(make_unique<UPlayerStrikeSkill>(this));
	
}

APlayer::~APlayer()
{
}


void APlayer::LevelUp()
{
	constexpr int MAX_LEVEL = 10;
}

void APlayer::UseItem()
{
}

void APlayer::PlayTurn(ACharacter* Target)
{
	ACharacter::PlayTurn(Target);
	for (int i = 0; i < Skills.size(); i++)
	{
		cout << i + 1 << ". " << Skills[i]->GetSkillName() << endl;
	}
	int choice = 0;
	while (choice < 1 || choice > Skills.size())
	{
		cout << "스킬을 선택하세요: ";
		cin >> choice;
		if (choice < 1 || choice > Skills.size())
		{
			cout << "잘못된 입력입니다." << endl;
		}
	}
	Skills[choice - 1]->Play(Target);
}
