#include "Monster.h"
#include "Character/Character.h"


using namespace std;


AMonster::AMonster(string NewName, const FUnitStat& NewStat)
    : ACharacter(NewName,NewStat)
{
}


AMonster::~AMonster()
{
	cout << "ACharacter 소멸됨" << endl;
}
void AMonster::Attack(ACharacter* Target)
{
   
    if (Target == nullptr) return;
    Target->TakeDamage(Stat.Atk);

    std::cout << Target->getName() << " 이(가) 공격합니다!\n";
}

void AMonster::TakeDamage(int DamageAmount)
{
    int FinalDamege = DamageAmount - getDef();
    if (FinalDamege <= 0) FinalDamege = 0;
    if (getRandomInt() < Stat.Critical) {
        FinalDamege *= 1.5f;
        cout << "치명적인 피해를 입혔습니다." << endl;
    }
    Stat.Hp -= FinalDamege;
    std::cout << Name << " 이(가) " << FinalDamege
        << " 피해를 입음. 남은 HP: " << Stat.Hp << "\n";
}