#include "Monster.h"
#include "Character.h"

using namespace std;


AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
}
