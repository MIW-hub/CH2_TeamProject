#pragma once
#include <string>

using namespace std;
class ACharacter;
class BattleManager
{

public:
	BattleManager();

	void RunBattle(ACharacter* Attacker, ACharacter* Defender);
	void  WaitForPlayerInput();
	bool BattleTurn(ACharacter* Attacker, ACharacter* Defender);
};

