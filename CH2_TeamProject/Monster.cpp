#include "Monster.h"
#include "Character/Character.h"





AMonster::AMonster(string M_name, int M_Hp, int M_Atk, int M_Def, int M_Critcal)
{
	Name = M_name;
	Hp = M_Hp;
	Atk = M_Atk;
	Def = M_Def;
	Critcal = M_Critcal;
}


AMonster::~AMonster()
{
	cout << "ACharacter 소멸됨" << endl;
}




