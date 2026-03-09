#include "BattleManager.h"
#include "Character.h"
#include <iostream>
using namespace std;

BattleManager::BattleManager()
{
}

void BattleManager::RunBattle(ACharacter* Attacker, ACharacter* Defender)
{
	while (true)
	{
		//플레이어 공격	              
		if (BattleTurn(Attacker, Defender) == false)
		{
			break;
		}
		//몬스터 공격        
		if (BattleTurn(Defender, Attacker) == false)
		{
			break;
		}
	}
}

void BattleManager::WaitForPlayerInput()
{
    system("pause");
    cout << endl;
}

bool BattleManager::BattleTurn(ACharacter* Attacker, ACharacter* Defender)
{
	WaitForPlayerInput();
	Attacker->PlayTurn(Defender);
	Attacker->ShowStat();
	Defender->ShowStat();
	cout << "" << endl;
	if (Defender->IsDead())
	{
		cout << Defender->GetName() << "가 쓰러졌습니다!" << Attacker->GetName() << "의 승리!" << endl;
		return false;
	}
	return true;    
}
