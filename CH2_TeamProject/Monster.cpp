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
void AMonster::Attack(ACharacter* Target)
{
    if (Target == nullptr) return;

    int Damage = Atk - Target->getDef();
    if (Damage < 1) Damage = 1;

    std::cout << Name << " 이(가) 공격합니다!\n";
    Target->TakeDamage(Damage);
}

void AMonster::TakeDamage(int DamageAmount)
{
    Hp -= DamageAmount;
    if (Hp < 0) Hp = 0;

    std::cout << Name << " 이(가) " << DamageAmount
        << " 피해를 입음. 남은 HP: " << Hp << "\n";
}