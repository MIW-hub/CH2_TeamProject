#include "Monster.h"
#include "Character/Character.h"


using namespace std;




AMonster::AMonster(const string& M_name, int M_Hp, int M_Atk, int M_Def, int M_Critcal)
    : ACharacter(M_name, M_Hp, M_Atk, M_Def, M_Critcal)
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
